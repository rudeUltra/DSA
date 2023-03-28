//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int idx,int wt[],int val[],int cap,int n,vector<vector<int>>&dp){
        if(idx==n-1){
            //check can we buy the last element or not siu
            if(wt[idx]<=cap){
                return val[idx];
            }
            else{
                return 0;
            }
        }
        
        if(dp[idx][cap]!=-1){
            return dp[idx][cap];
        }
        //two options pick or not pick siu
        int notpick=f(idx+1,wt,val,cap,n,dp);
        int pick=0;
        if(wt[idx]<=cap){
            pick=f(idx+1,wt,val,cap-wt[idx],n,dp)+val[idx];
        }
        
        return dp[idx][cap]=max(pick,notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return f(0,wt,val,W,n,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends