//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
          //2 pal ka aram de
        //lets try tabulations first
       
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       //ok recursion not gonna work sad xD
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0; //substring has to be continuous
                }
            }
        }
        
        //loop through entire array and check for max subarray siu
        
        //dp table gives us a way of checking each subarray easily siu
        
        //check for each subarray or i  is there a value or substring possible or not siu
        
        int ans=INT_MIN;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends