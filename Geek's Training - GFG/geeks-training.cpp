//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int f(int idx,vector<vector<int>>&points,int prev,vector<vector<int>>&dp){
      if(idx>=points.size()){
          return 0; //siu
      }
      
      if(dp[idx][prev+1]!=-1){
          return dp[idx][prev+1];
      }
      int ans=INT_MIN;
      for(int i=0;i<3;++i){
          if(i!=prev || prev==-1){
              ans=max(ans,f(idx+1,points,i,dp)+points[idx][i]);
          }
      }
      
      return dp[idx][prev+1]=ans;
  }
  
  
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n+1,vector<int>(4,-1)); //only 3 options so siu
        return f(0,points,-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends