// Given n and k, return the kth permutation sequence.

// Example 1:

// Input: n = 3, k = 3
// Output: "213"

class Solution {
public:
    string getPermutation(int n, int k) {

        k--;

        vector<int> arr; string s = ""; int per = 1;

        for(int i=1;i<=n;i++){
            per = per*i;
            arr.push_back(i);
        }

        per=per/n;

        while(true){
            s.push_back(arr[k/per]+'0');
            arr.erase(arr.begin()+(k/per));
            if(arr.size()==0) break;
            k = k%per;
            per = per/arr.size();
        }
        return s;
    }
};
