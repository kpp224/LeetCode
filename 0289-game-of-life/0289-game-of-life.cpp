class Solution {
public:
    int row[8] = {0,0,-1,1,-1,-1,1,1};
    int col[8] = {-1,1,0,0,-1,1,-1,1};

    bool isValid(int i, int j, int n, int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board[0].size();
        int n = board.size();

        // vector<vector<int>> copyBoard(m, vector<int>(n));

        vector<vector<int>> copyBoard = board;

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         copyBoard[i][j] = board[i][j];
        //     }
        // }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int liveCounts = 0;

                for(int k = 0; k < 8; k++){
                    if(isValid(i+row[k],j+col[k],n,m) && copyBoard[i+row[k]][j+col[k]] == 1){
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