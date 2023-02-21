//Given a list arr of N integers, print sums of all subsets in it.

// Input:
// N = 2
// arr[] = {2, 3}
// Output:
// 0 2 3 5

#include <bits/stdc++.h>

void add(vector<int> &num,vector<int> &chk,vector<int> &ans){

    int sum=0;
    for(int i=0;i<num.size();i++){
        if(chk[i]==1){
            sum+=num[i];
        }
    }
    ans.push_back(sum);
}

void solve(int i, vector<int> &num, vector<int> &chk, vector<int> &ans){

    if(i==num.size()){

        add(num,chk,ans);
    }

    else{

        chk[i] = 1; //take
        solve(i+1, num, chk, ans);
        chk[i] = -1; //not take
        solve(i+1, num, chk, ans);
    }
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.

    int n = num.size();

    vector<int> chk(n,-1);
    vector<int> ans;
    solve(0,num,chk,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
