//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int m = 1000000007;
        sort(arr, arr+n, greater<int>());
        
        int mat[n][sum+1];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){
                
                if(j==0){
                    mat[i][j] = 1;
                }
                
                else if(i==0 && j!=0){
                    if(arr[i]==j) mat[i][j] = 1;
                    else mat[i][j] = 0;
                }
                
                else if(arr[i]<=j){
                    mat[i][j] = ( (mat[i-1][j] % m)+(mat[i-1][j-arr[i]] % m) ) % m;
                }
                else{
                    mat[i][j] = mat[i-1][j] % m;
                }
                
            }
   
        }

        return mat[n-1][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
