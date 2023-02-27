// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(); 
        string r = s; reverse(r.begin(), r.end());

        int mat[n+1][n+1];

        for(int i=0;i<=n;i++) mat[i][0] = 0;
        for(int i=0;i<=n;i++) mat[0][i] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){

                if(s[i-1]==r[j-1]){
                    mat[i][j] = 1 + mat[i-1][j-1];
                }
                else{
                    mat[i][j] = max(
                        mat[i][j-1],
                        mat[i-1][j]
                    );
                }
            }
        }
        return mat[n][n];
    }
};
