// Given an integer array nums that may contain duplicates, return all possible
// subsets
//  (the power set).
//
// The solution set must not contain duplicate subsets. Return the solution in any order.
//
//
//
// Example 1:
//
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

#include <bits/stdc++.h>
using namespace std;



void solve(vector<int> &arr, int i, vector<int> &curr){

  for(int i=0;i<curr.size();i++){
    cout<<curr[i]<<" ";
  }
  cout<<endl;

  int n = arr.size();

  int a = arr[i];
  curr.push_back(a);

  for(int j=i;j<n;j++){

    if(arr[j]!=a){
      solve(arr,j,curr);
      curr.push_back(a);
      a = arr[j];
    }
  }

}

int main(){

  vector<int> v = {1,1,3};
  vector<int> curr;
  solve(v,0,curr);
}
