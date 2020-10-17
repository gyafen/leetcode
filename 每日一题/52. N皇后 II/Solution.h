#include <vector>

using namespace std;

int total;

class Solution {
public:
    int conflict(vector<vector<int>> chessboard, int row, int col, int n){
        //左
        for(int mov_col = col - 1; mov_col >= 0; --mov_col){
            if(chessboard[row][mov_col] == 1){
                return 1;
            }
        }
        //左上
        for(int mov_col = col-1, mov_row = row-1; (mov_col>=0)&&(mov_row>=0); --mov_col, --mov_row){
            if(chessboard[mov_row][mov_col] == 1){
                return 1;
            }
        }
        //上
        for(int mov_row = row-1; mov_row>=0; --mov_row){
            if(chessboard[mov_row][col] == 1){
                return 1;
            }
        }
        //右上
        for(int mov_row = row-1, mov_col = col+1; (mov_row>=0)&&(mov_col<n); mov_row--, mov_col++)
        {
            if(chessboard[mov_row][mov_col] == 1){
                return 1;
            }
        }
        return 0;
    }

    void search(vector<vector<int>> &chessboard, int line, int n){
        if(line < n){
            for(int i = 0; i < n; ++i){
                chessboard[line][i] = 1;
                if(!conflict(chessboard, line, i, n)){
                    search(chessboard, line+1, n);
                }
                chessboard[line][i] = 0;
            }
        }
        else if(line == n){
            ++total;
        }
    }

    int totalNQueens(int n) {
        vector<vector<int>> chessboard;
        total = 0;
        for(int i = 0; i < n; i++){
            vector<int> line(n, 0);
            chessboard.push_back(line);
        }
        search(chessboard, 0, n);
        return total;
    }
};
