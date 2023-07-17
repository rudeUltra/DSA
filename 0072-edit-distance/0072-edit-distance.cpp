class Solution {
public:
    int minDistance(string word1, string word2) {
        //striver god :))
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return stringmatch(n-1,m-1,word1,word2,dp);
    }
    int stringmatch(int i,int j,string word1,string word2,vector<vector<int>>&dp){
        
        
        if(i<0){
            return j+1; //even if minus then -1 + 1 =0 xD
        }
        if(j<0){
            return i+1;
        }
        //explore all possibilities
        if(dp[i][j]!=-1){
            return dp[i][j]; //overlapping subproblems
        }
        //if match noice no need to edit
        if(word1[i]==word2[j]){
            return dp[i][j]=stringmatch(i-1,j-1,word1,word2,dp)+0;
        }
        //explore all possibilites dr strange xD
        return dp[i][j] = 1+min(stringmatch(i,j-1,word1,word2,dp),min(stringmatch(i-1,j-1,word1,word2,dp),stringmatch(i-1,j,word1,word2,dp)));
            
        
    }
};