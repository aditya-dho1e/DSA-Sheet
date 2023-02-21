// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency
//  of at least one of the chosen numbers is different.
  
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

class Solution {
public:

    void solve(int i, int t, vector<int> &curr, vector<int> &arr,  vector< vector<int> > &ans){

        if(t==0){
            ans.push_back(curr);
        }

        else{

            if(t>=0){

                for(i;i<arr.size();i++){
                curr.push_back(arr[i]);
                solve(i,t-arr[i],curr,arr,ans);
                curr.pop_back();
            }
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> curr;

        solve(0,target,curr,candidates,ans);

        return ans;
    }
};
