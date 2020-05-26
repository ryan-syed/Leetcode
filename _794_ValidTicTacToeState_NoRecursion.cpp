class Solution {
public:
    bool isOver(vector<string>& board, char ch) {
        for(int i = 0; i < 3; i++)
            if(board[i][0] == ch && board[i][1] == ch && board[i][2] == ch)
                return true;
        
        for(int j = 0; j < 3; j++)
            if(board[0][j] == ch && board[1][j] == ch && board[2][j] == ch)
                return true;
        
        if(board[0][0] == ch && board[1][1] == ch && board[2][2] == ch)
            return true;
        if(board[2][0] == ch && board[1][1] == ch && board[0][2] == ch)
            return true;
        return false;
    }
    
    bool validTicTacToe(vector<string>& board) {
        int countX = 0;
        int countO = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 'X')
                    countX++;
                else if(board[i][j] == 'O')
                    countO++;
            }
        }
        
        // Possibility 1: either X = O + 1 and game finished(X won)/ongoing
		// Possibility 2: X = O and the game finished(O won)/ongoing
        return ((countX - 1 == countO) && 
            ((isOver(board, 'X') && !isOver(board, 'O')) ||
             (!isOver(board, 'X') && !isOver(board, 'O')))) ||
            ((countX == countO) && 
             ((!isOver(board, 'X') && isOver(board, 'O')) ||
             (!isOver(board, 'X') && !isOver(board, 'O'))));
    }
};