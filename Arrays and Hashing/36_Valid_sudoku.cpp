#include <bits/stdc++.h>
#define fore(x,init,limit) for(int x=init; x<limit; x++)
using namespace std;
typedef long long ll;

bool isValidSudokuV1(vector<vector<char>>& board) {
    for(auto fila : board){
        unordered_set<char> uset;
        for(char digit : fila){
            if(digit != '.'){
                if(uset.insert(digit).second == false){
                    return false;
                }
            }
        }
    }
    for(int i=0; i<9; i++){
        unordered_set<char> uset;
        for(int j=0; j<9; j++){
            if(board[j][i] != '.'){
                if(uset.insert(board[j][i]).second == false){
                    return false;
                }
            }
        }
    }
    for(int i=0; i<9; i+=3){
        for(int j=0; j<9; j+=3){
            unordered_set<char> uset;
            for(int n=i; n<i+3; n++){
                for(int k=j; k<j+3; k++){
                    if(board[n][k] != '.'){
                        if(uset.insert(board[n][k]).second == false){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool isValidSudokuV2(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<char>> subBoxSet;
    for(int i=0; i<9; i++){
        unordered_set<char> rowsSet, colsSet;
        for(int j=0; j<9; j++){
            if(board[i][j] != '.'){
                if(rowsSet.insert(board[i][j]).second == false || subBoxSet[i/3*3+j/3].insert(board[i][j]).second == false){
                    return false;
                }
            }
            if(board[j][i] != '.'){
                if(colsSet.insert(board[j][i]).second == false){
                    return false;
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char> > &board){
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
    
    for(int i = 0; i < board.size(); ++ i)
        for(int j = 0; j < board[i].size(); ++ j)
            if(board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                if(used1[i][num] || used2[j][num] || used3[k][num]){
                    return false;
                }
                else{
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
            }
    return true;
}

int main(){
    vector<vector<char>> board = {
{'.','.','.','.','5','.','.','1','.'},
{'.','4','.','3','.','.','.','.','.'},
{'.','.','.','.','.','3','.','.','1'},
{'8','.','.','.','.','.','.','2','.'},
{'.','.','2','.','7','.','.','.','.'},
{'.','1','5','.','.','.','.','.','.'},
{'.','.','.','.','.','2','.','.','.'},
{'.','2','.','9','.','.','.','.','.'},
{'.','.','4','.','.','.','.','.','.'}
};

    if(isValidSudoku(board)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}
