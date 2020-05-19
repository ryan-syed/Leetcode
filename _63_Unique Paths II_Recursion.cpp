#define vvi vector<vector<int> >
#define vi vector<int>

class Solution {
public:
    int helper(vi &grid, int m, int n, int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i * m + j] == -1)
            return 0;
        
        if(grid[i * m + j] == 0) {
            if(i == n - 1 && j == m - 1) 
                grid[i * m + j] = 1;
            else
                grid[i * m + j] = helper(grid, m, n, i + 1, j) + helper(grid, m, n, i, j + 1);
        }
        return grid[i * m + j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0)
            return 0;
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vi grid(n * m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                if(obstacleGrid[i][j] == 1)
                    grid[i * m + j] = -1;
        }
        
        return helper(grid, m, n, 0, 0);
    }
};