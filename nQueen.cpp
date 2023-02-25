// Problem Statement: 

// The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. 
// Given an integer n, display all distinct solutions to the n -queens puzzle. 
// Each solution contains a distinct boards configuration of the queen’s placement, 
// where ‘Q’ and ‘.’ indicate queen and empty space respectively.

//find the leetcode's code below the given code

#include <bits/stdc++.h>
using namespace std;

void display(char*mat[], int n,vector<vector<string>> &ans){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}

bool issafe(int n, int row, int col, char *mat[]){

  //row
  for(int i=col-1; i>=0; i--){
    if(mat[row][i]=='Q') return false;
  }

  //upper-diagonal
  for(int i=row-1,j=col-1; i>=0&&j>=0; i--,j--){
    if(mat[i][j]=='Q') return false;
  }

  //lower-diagonal
  for(int i=row+1,j=col-1; i<n&&j>=0; i++,j--){
    if(mat[i][j]=='Q') return false;
  }

  return true;
}

void solve(char*mat[],int i,int n,vector<vector<string>> &ans){

  if(i==n){
    display(mat,n,ans);
    cout<<endl;
  }

  else{

    for(int r=0;r<n;r++){

      if(issafe(n,r,i,mat)){
        mat[r][i] = 'Q';
        solve(mat,i+1,n,ans);
        mat[r][i] = '.';
      }
    }
  }
}

int main(){
  int n; cin>>n;
  char*mat[n];

  for(int i=0;i<n;i++){
    mat[i]=(char*)calloc(sizeof(int),n);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      mat[i][j] = '.';
    }
  }
  vector<vector<string>> ans;
  solve(mat,0,n,ans);
  return 0;
}

//LeetCode's Solution:-

// class Solution {
// public:

//     void add(vector<vector<char>> &mat, vector<vector<string>> &ans){
//         vector<string> v;
//         for(int i=0;i<mat.size(); i++){
//             string s = "";
//             for(int j=0;j<mat.size();j++){
//                 s.push_back(mat[i][j]);
//             }
//             v.push_back(s);
//         }
//         ans.push_back(v);
//     }

//     bool issafe(vector<vector<char>> &mat, int r, int c, int n){

//         //horizontal
//         for(int i=c-1;i>=0;i--){
//             if(mat[r][i]=='Q') return false;
//         }

//         //upper-diagonal
//         for(int i=r-1,j=c-1; i>=0&&j>=0; i--,j--){
//             if(mat[i][j]=='Q') return false;
//         }

//         //lower-diagonal
//         for(int i=r+1,j=c-1; i<n&&j>=0; i++,j--){
//             if(mat[i][j]=='Q') return false;
//         }

//         return true;
//     }

//     void solve(vector<vector<char>> &mat,int i, int n, vector<vector<string>> &ans){

//         if(i==n){
//             add(mat,ans);
//         }

//         else{

//             for(int r=0; r<n; r++){

//                 if(issafe(mat,r,i,n)){

//                     mat[r][i] = 'Q';
//                     solve(mat,i+1,n,ans);
//                     mat[r][i] = '.';
//                 }
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<char>> mat;
//         mat.assign(n,vector<char> (n,'.'));
//         vector<vector<string>> ans;
//         solve(mat,0,n,ans);
//         return ans;
//     }
// };
