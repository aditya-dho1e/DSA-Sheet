// Given a string s, partition s such that every
// substring
//  of the partition is a
// palindrome
// . Return all possible palindrome partitioning of s.



// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

#include <iostream>

#include <bits/stdc++.h>

using namespace std;

bool pal(string s){

    if(s==""){
        return false;
    }

    int n = s.size() - 1;

    for(int i=0; i<s.size()/2; i++){

        if(s[i]!=s[n]){

            return false;
        }
        n--;
    }
    return true;
}

void solve(string s, vector<string> &curr, vector<vector<string>> &ans){

    if(s==""){
        ans.push_back(curr);
        return;
    }

    for(int i=0;i<s.size();i++){

        string sub = s.substr(0,i+1);

        if(pal(sub)){
            curr.push_back(sub);
            solve(s.substr(i+1,s.size()),curr,ans);
            curr.pop_back();
        }
    }
}

int main()
{
    string s = "aabb";

    vector<vector<string>> ans;
    vector<string> curr;

    solve(s,curr,ans);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
    }
}
