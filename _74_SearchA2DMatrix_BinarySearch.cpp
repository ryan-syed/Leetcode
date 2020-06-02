class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int lo = 0;
        int hi = m * n - 1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int i = mid / m;
            int j = mid % m;
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        return false;
    }
};