// Given an integer array nums, find the subarray
// with the largest sum, and return its sum.
  
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

class Solution {
public:
    int maxSubArray(vector<int>&arr) {
        int sum=0,maxi=INT_MIN,n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(maxi,sum);
            if(sum<0)sum=0;
        }
        return maxi;
    }
};
