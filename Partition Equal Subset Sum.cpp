// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum = 0,n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size();i++) sum += nums[i];

        if(sum%2!=0) return false;
        else sum/=2;

        bool mat[n][sum+1];

        for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){

                if(j==0) mat[i][j] = 1;

                if(i==0){
                    if(nums[i]==j) mat[i][j] = 1;
                    else mat[i][j] = 0;
                }

                else{

                    if(nums[i]<=j){
                        mat[i][j] = (mat[i-1][j-nums[i]] | mat[i-1][j]);
                    }
                    else{
                        mat[i][j] = mat[i-1][j];
                    }
                }
            }
        }
        return mat[n-1][sum];
    }
};
