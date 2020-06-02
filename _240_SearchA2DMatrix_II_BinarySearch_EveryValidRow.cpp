class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0)
            return false;
        int m = matrix[0].size();
        
        if(m == 0)
            return false;
        
        if(target < matrix[0][0] || target > matrix[n - 1][m - 1])
            return false;
        
        for(int i = 0; i < n; i++) {
            if(target < matrix[i][0])
                return false;
            if(target > matrix[i][m - 1])
                continue;
            
            if(binary_search(matrix[i].begin(), matrix[i].end(), target))
                return true;
        }
        
        return false;
    }
};