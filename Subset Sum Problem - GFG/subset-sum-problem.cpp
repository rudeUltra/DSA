//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int f(int idx,vector<int>&arr,int sum,vector<vector<int>>&dp){
        //base case
        if(sum==0){
            return 1;
        }
        
        if(idx==0){
            if(sum==arr[idx]){
                return 1; //possible
            }
            return 0; //no way siu
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        
        int pick=0;
        int notpick=f(idx-1,arr,sum,dp);
        if(arr[idx]<=sum){
            pick=f(idx-1,arr,sum-arr[idx],dp);
        }
        if(pick | notpick){
            dp[idx][sum]=1;
        }
        else{
            dp[idx][sum]=0;
        }
   
        return dp[idx][sum];
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        //for this sum at this index did u find any sus siu
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return f(arr.size()-1,arr,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends