//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int f(int idx,vector<int>&height,vector<int>&dp){
      if(idx==0){
          return 0;
      }
      if(idx<0){
          return INT_MAX; //min xD
      }
      
      if(dp[idx]!=-1){
          return dp[idx];
      }
      int step1=INT_MAX;
      int step2=INT_MAX;
      if(idx>0){
           step1=f(idx-1,height,dp)+abs(height[idx]-height[idx-1]);
      }
      if(idx>1){
          //can take 2 steps siu
          step2=f(idx-2,height,dp)+abs(height[idx]-height[idx-2]);
      }
      
      return dp[idx]=min(step1,step2);
      
      
  }
  
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return f(n-1,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends