class Solution {
public:
    vector<int> arr;
    int helper(int m, int n, int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        
        if(arr[i * m + j] == 0) {
            if(i == n - 1 || j == m - 1)
                arr[i * m + j] = 1;
            else
                arr[i * m + j] = helper(m, n, i + 1, j) + helper(m, n, i, j + 1);
        }
        
        return arr[i * m + j];
    }
    
    int uniquePaths(int m, int n) {
        arr = vector<int>(m * n, 0);
        int count = helper(m, n, 0, 0);
        return count;
    }
};