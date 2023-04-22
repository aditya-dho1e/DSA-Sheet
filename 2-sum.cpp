// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

class Solution {
public:
    vector<int> twoSum(vector<int>&arr, int target) {
        int left=0,right=arr.size()-1;

        vector<pair<int,int>>temp(arr.size());

        for(int i=0;i<arr.size();i++){
            temp[i]={arr[i],i};
        }

        sort(temp.begin(),temp.end());

        vector<int>ans;

        while(left<right){

            int sum=temp[left].first+temp[right].first;

            if( sum<target ) left++;
            else if(sum>target) right--;

            else if(sum==target){
                ans={temp[left].second,temp[right].second};
                break;
            }
        }
        
        return ans;
    }
};
