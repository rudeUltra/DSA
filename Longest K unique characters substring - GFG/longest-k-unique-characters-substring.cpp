//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
      int left=0;
      int right=0;
      
      unordered_map<char,int>mp;
      int ans=0;
      int count=0; //to hold unique characters siu
      while(right<s.length()){
          mp[s[right]]++;
          if(mp[s[right]]==1){
              //unique character hm
              count++;
          }
          
          if(count==k){
              //exactly k unique
              ans=max(ans,(right-left+1));
          }
         
          while(mp.size()>k){
              mp[s[left]]--;
              if(mp[s[left]]==0){
                  count--;
                  mp.erase(s[left]);
              }
              left++;
          }
          
          right++;
          
      }
      return ans==0?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends