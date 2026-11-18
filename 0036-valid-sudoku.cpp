// LeetCode 36: Valid Sudoku | O(1) for a 9x9 board
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 bool isValidSudoku(vector<vector<char>>& b) {
  bool row[9][9]={},col[9][9]={},box[9][9]={};
  for(int r=0;r<9;++r)for(int c=0;c<9;++c)if(b[r][c]!='.'){
   int d=b[r][c]-'1',k=(r/3)*3+c/3;
   if(row[r][d]||col[c][d]||box[k][d])return false;
   row[r][d]=col[c][d]=box[k][d]=true;
  } return true;
 }
};