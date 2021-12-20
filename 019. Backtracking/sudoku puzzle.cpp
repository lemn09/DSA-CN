
#include<bits/stdc++.h>
using namespace std;

#define N 9

// check if value is valid or not, acc. to given constraints
bool isSafe(int grid[N][N], int x, int y, int val){
    // x: row , y: col
    
    // check 1: col check
    for(int i=0; i<9; i++){
        if(grid[i][y] == val){
            return false;
        }
    }
    
    // check 2: row check
    for(int i=0; i<9; i++){
        if(grid[x][i] == val){
            return false;
        }
    }
    
    // check 3: box check
    int rowFactor= x - (x%3);
    int colFactor= y - (y%3);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[i+rowFactor][j+colFactor] == val){
                return false;
            }
        }
    }
    
    return true;
}


// returns if empty position is available, and also return row and col val(refrence var)
bool findEmpty(int grid[N][N], int &row, int &col){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j] == 0){
                row=i;
                col= j;
                return true;
            }
        }
    }
    return false;
}

// returns if sudoku can be solved with the given value
bool solveSudoku(int grid[N][N]){
    int row, col;
    // if no empty position is present => sudoku is solved
    if(findEmpty(grid, row, col) == false){
        return true;
    }
    // else: insert value from 1 to 9 and backTrack until the sudoku is solved
    for(int i=1; i<=9; i++){
        // check if value is valid, acc. to the constraints
        if(isSafe(grid, row, col, i) == true){
            grid[row][col]= i;
            // check if the sudoku puzzle can be fully solved with the value: i
            if(solveSudoku(grid)){
                return true;
            }
            // else reassign 0 and backtrack
            grid[row][col]=0;
        }
    }
    return false;
}

int main(){
    int grid[N][N];
    // Input format: each row is of 9 char, which is stored as string and then stored in the array grid
    for(int i=0; i<N; i++){
        string s;
        cin>>s;
        for(int j=0; j<s.length(); j++){
            grid[i][j]= s[j] - '0';
        }
    }
    
    solveSudoku(grid);
    // printing output
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}