// LeetCode 37: Sudoku Solver | Backtracking
#include <bits/stdc++.h>
using namespace std;
class Solution { public:
 void solveSudoku(vector<vector<char>>& board) {
  bool row[9][9]={},col[9][9]={},box[9][9]={};
  for(int r=0;r<9;++r)for(int c=0;c<9;++c)if(board[r][c]!='.'){
   int d=board[r][c]-'1',b=(r/3)*3+c/3;row[r][d]=col[c][d]=box[b][d]=true;
  }
  function<bool()> dfs=[&](){
   int br=-1,bc=-1,best=10;
   for(int r=0;r<9;++r)for(int c=0;c<9;++c)if(board[r][c]=='.'){
    int b=(r/3)*3+c/3,cnt=0;
    for(int d=0;d<9;++d)if(!row[r][d]&&!col[c][d]&&!box[b][d])++cnt;
    if(cnt<best){best=cnt;br=r;bc=c;}
   }
   if(br==-1)return true;
   int b=(br/3)*3+bc/3;
   for(int d=0;d<9;++d)if(!row[br][d]&&!col[bc][d]&&!box[b][d]){
    board[br][bc]=char('1'+d);row[br][d]=col[bc][d]=box[b][d]=true;
    if(dfs())return true;
    row[br][d]=col[bc][d]=box[b][d]=false;board[br][bc]='.';
   } return false;
  }; dfs();
 }
};