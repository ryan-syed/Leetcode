class Solution {
public:
    // start time 20:16
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = 9;
        int col = 9;
        
        vector<int> unit(10, 0);
        
        for(int i = 0; i < row; i++){
            unit = vector<int>(10, 0);
            for(int j = 0; j < col; j++)
            {
                if(board[i][j] != '.' && unit[board[i][j]]++)
                        return false;
            }
        }
        
        for(int j = 0; j < col; j++){
            unit = vector<int>(10, 0);
            for(int i = 0; i < row; i++)
            {
                if(board[i][j] != '.' && unit[board[i][j]]++)
                    return false;
            }
        }
        
        for(int k = 0; k < 9; k++) {
            int iStart = (k / 3) * 3;
            int jStart = (k % 3) * 3;
            unit = vector<int>(10, 0);
            for(int i = iStart; i < iStart + 3; i++){
                for(int j = jStart; j < jStart + 3; j++)
                {
                    if(board[i][j] != '.' && unit[board[i][j]]++)
                        return false;
                }
            }
        }
        
        return true;
    }
};