class Solution {
public:
    
    int f(int i,int j,vector<int>&nums,int flag,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        int ans=0;
        if(flag==1){
            ans=INT_MIN;
        }
        else{
            ans=INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(flag==1){
            int temp1=f(i+1,j,nums,0,dp)+nums[i];
            int temp2=f(i,j-1,nums,0,dp)+nums[j];
            
            ans=max(temp1,temp2);
        }
        else{
            
            int temp1=f(i+1,j,nums,1,dp);
            int temp2=f(i,j-1,nums,1,dp);
            
            ans=min(temp1,temp2);
            
        }
        return dp[i][j]=ans;
    }
    
    bool predictTheWinner(vector<int>& nums) {
        //calculate Alex score
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        int score=f(0,n-1,nums,1,dp);
        cout<<score;
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        if(sum%2==1){
            if(score>sum/2){
                return true;
            }
            else{
                return false;
            }
        }
        if(score>=sum/2){
            return true;
        }
        
        return false;
        
    }
};