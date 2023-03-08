// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]


class Solution {
public:

    void solve(string s, vector<string> &arr, vector<int> &n, int i,vector<string> &ans){

        if(i==n.size()){
            if(s=="") return;
            ans.push_back(s);
        }
        else{

            int digit = n[i];
            string str = arr[digit];
            for(int j=0;j<str.size();j++){
                s.push_back(str[j]);
                solve(s,arr,n,i+1,ans);
                s.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<int> n(digits.size());

        for(int i=0;i<digits.size();i++){
            n[i] = digits[i] - '0';
        }

        vector<string> ans;
        vector<string> arr = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve("",arr,n,0,ans);

        return ans;
    }
};
