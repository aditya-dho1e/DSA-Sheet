// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

class Solution {
public:

    void solve(int i, int t, vector<int> &curr, vector<int> &arr, vector<vector<int>> &ans){

        if(t==0){
            ans.push_back(curr);
        }

                for(int j=i; j<arr.size();j++){

                    if((j!=i) && (arr[j]==arr[j-1])) continue;

                    if(t - arr[j] < 0) break;

                    curr.push_back(arr[j]);
                    solve(j+1,t-arr[j],curr,arr,ans);
                    curr.pop_back();
                }
            }
    

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0,target,curr,candidates,ans);

        return ans;
    }
};
