class Solution {
public:
bool ok=false;
    vector<vector<int>>dp;
    int fun(int ind1, int ind2, int prev, vector<int>&arr1, vector<int>&arr2)
    {
        if(ind1==arr1.size())
        {
            ok=true;
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int ans=1e9;
        if(arr1[ind1]>prev) // do choice hai current pr change karo ya na karo
        {
            // to main arr1[ind1] k sath bhi aage badh skta hu
            int noChange=fun(ind1+1,ind2,arr1[ind1],arr1,arr2);
            ans=min(ans,noChange);
        }
          ind2=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
          int change=1e9;
          // arr2 k sabse pass wale elem se change karlu isko
          if(ind2<arr2.size()) change=1+fun(ind1+1,ind2+1,arr2[ind2],arr1,arr2);
          ans=min(ans,change);
          return  dp[ind1][ind2]=ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int n1=arr1.size(),n2=arr2.size();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        int ans=fun(0,0,-1,arr1,arr2);
        if(!ok) return -1;
        return ans;
    }
};