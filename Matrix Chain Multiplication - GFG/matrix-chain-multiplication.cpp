//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int i,int j,int arr[],vector<vector<int>>&dp){
        if(i>=j){
            //single matrix no need of operations siU
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;++k){
            int temp=f(i,k,arr,dp)+f(k+1,j,arr,dp)+(arr[i-1]*arr[k]*arr[j]);
            ans=min(ans,temp);
        }
        return dp[i][j]=ans; //for this partition siu
    }



    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        
        return f(1,N-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends