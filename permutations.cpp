// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution {
public:

    void solve(vector<int> &arr, int i, vector<vector<int>> &ans){
        if(i==arr.size()){
            ans.push_back(arr);
        }

        for(int idx=i;idx<arr.size();idx++){
            swap(arr[i],arr[idx]);
            solve(arr,i+1,ans);
            swap(arr[i],arr[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};
