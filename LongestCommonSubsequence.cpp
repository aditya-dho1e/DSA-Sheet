// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size(), m = text2.size();

        int*mat[n+1];

        for(int i=0;i<=n;i++){
            mat[i] = (int*)calloc(sizeof(int),m+1);
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                //if equal
                if(text1[i-1]==text2[j-1]){ // -1 because we did n+1 & m+1
                    int x = max( mat[i][j-1], mat[i-1][j] );
                    x = max( (1+mat[i-1][j-1]), x );
                    mat[i][j] = x; // mat[i][j] = 1 + mat[i-1][j-1] is better
                }

                //if not equal
                else{
                    mat[i][j] = max( mat[i][j-1], mat[i-1][j] );
                }
            }
        }

        return mat[n][m];
    }
};
