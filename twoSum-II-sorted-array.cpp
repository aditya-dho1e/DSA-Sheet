class Solution {
public:
    vector<int> twoSum(vector<int>&arr, int t) {
        int n = arr.size();

        int left=0,right=n-1;

        vector<int> ans;

        while(left<right){
            int sum = arr[left]+arr[right];

            if(sum<t)left++;
            else if (sum>t)right--;
            if(sum==t){
                ans={left+1,right+1};
                break;
            }
        }
        return ans;
    }
};
