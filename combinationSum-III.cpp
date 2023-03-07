// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

class Solution {
public:

    void solve(int n, int c, int i, vector<vector<int>> &ans, vector<int> &curr){
        if(c==0 & n==0){
            ans.push_back(curr);
        }
        else{

            for(int j=i;j<=9;j++){
                if((j>c) || (n==0)) break;
                curr.push_back(j);
                solve(n-1,c-j,j+1,ans,curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(k,n,1,ans,curr);
        return ans;
    }
};
