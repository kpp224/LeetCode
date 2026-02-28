class Solution {
public:
    int row[8] = {0,0,-1,1,-1,-1,1,1};
    int col[8] = {-1,1,0,0,-1,1,-1,1};

    bool isValid(int r, int c, int rows, int cols){
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board[0].size();
        int m = board.size();

        vector<vector<int>> copyBoard(m, vector<int>(n));

        // vector<vector<int>> copyBoard = board;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                copyBoard[i][j] = board[i][j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int liveCounts = 0;

                for(int k = 0; k < 8; k++){
                    int new_row = i + row[k];
                    int new_col = j + col[k];
                    if(isValid(new_row,new_col,m,n) && copyBoard[new_row][new_col] == 1){
                        liveCounts++;
                    }
                }

                if(copyBoard[i][j] == 0 && liveCounts == 3){
                    board[i][j] = 1;
                }
                else if(copyBoard[i][j] == 1 && (liveCounts < 2 || liveCounts > 3)){
                    board[i][j] = 0;
                }
                else{
                    board[i][j] = copyBoard[i][j];
                }
            }
        }

    }
};