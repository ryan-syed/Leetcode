#define vvi vector<vector<int> >
#define vi vector<int>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0)
            return 0;
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vi grid(n * m, 0);
        
        for(int i = 0; i < n; i++)
        {
            if(obstacleGrid[i][0] == 0)
                grid[i * m] = 1;
            else
                break;
        }
        
        for(int j = 0; j < m; j++)
        {
           if(obstacleGrid[0][j] == 0)
                grid[j] = 1;
            else
                break; 
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[i][j] == 1)
                    grid[i * m + j] = 0;
                else 
                    grid[i * m + j] = grid[(i - 1) * m + j] + grid[i * m + (j - 1)];
            }
        }
        
        return grid[m * n - 1];
    }
};