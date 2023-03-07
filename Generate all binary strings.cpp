// Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.

// A binary string is that string which contains only 0 and 1.

// Example 1:

// Input:
// N = 3
// Output:
// 000 , 001 , 010 , 100 , 101

#include<bits/stdc++.h>
using namespace std;

void solve(int n, string s, int i){
    if(n==0){
        cout<<s<<endl;
        return;
      }
    else{
      if(i==0){
        solve(n-1,s+"0",0);
        solve(n-1,s+"1",1);
      }
    else{
        solve(n-1,s+"0",0);
    }
  }
}

int main(){
  solve(3,"",0);
  return 0;
}
