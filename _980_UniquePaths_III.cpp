// Takes a long time though, should check for faster solution later
#define vvi vector<vector<int> >
#define vvb vector<vector<bool> >
#define vi vector<int>
#define vb vector<bool>

class Solution {
public:
    int helper(vvi &grid, vvb visited, int i, int j, int n, int m, int nonObstacles) {
        if(i < 0 || i >= n || j < 0 || j >= m || -1 == grid[i][j] || visited[i][j])
            return 0;
        if(2 == grid[i][j])
            return nonObstacles ? 0 : 1;
        
        visited[i][j] = true;
        if(grid[i][j] == 0)
            nonObstacles--;
        return helper(grid, visited, i - 1, j, n, m, nonObstacles) +
               helper(grid, visited, i , j + 1, n, m, nonObstacles) +
               helper(grid, visited, i + 1, j, n, m, nonObstacles) +
               helper(grid, visited, i, j - 1, n, m, nonObstacles);
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vvb visited(n, vb(m, false));
        
        int i = -1, j = -1;
        int nonObstacles = 0;
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                if(grid[x][y] == 1)
                {
                    i = x;
                    j = y;
                }
                else if(grid[x][y] == 0)
                    nonObstacles++;
            }
        }
        return helper(grid, visited, i, j, n, m, nonObstacles);
    }
};