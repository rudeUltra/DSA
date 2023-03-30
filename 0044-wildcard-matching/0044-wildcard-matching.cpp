class Solution {
public:
    string k;
    string k1;
    int getans(int i,int j,vector<vector<int>>&dp)
    {
      
        if(i<0 && j<0)
        {
            return 1;
        }
        if(i>=0 && j<0)
        {
            // int flag=1;
            while(i>=0)
            {
                if(k[i]!='*')
                {
                    return 0;
                }
                i--;
            }
            return 1;
        }
        if(i<0 && j>=0)
            return false;
          if(dp[i][j]!=-1)
            return dp[i][j];
        if(k[i]==k1[j] || k[i]=='?')
        {
            return dp[i][j]=getans(i-1,j-1,dp);
        }
        else if(k[i]=='*')
        {
            return dp[i][j]=getans(i,j-1,dp) ||getans(i-1,j,dp);
        }
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        k=p;
        k1=s;
        vector<vector<int>>dp(p.size(),vector<int>(s.size(),-1));
        int l=getans(p.size()-1,s.size()-1,dp);
        if(l)
            return true;
        else
            return false;
    }
};