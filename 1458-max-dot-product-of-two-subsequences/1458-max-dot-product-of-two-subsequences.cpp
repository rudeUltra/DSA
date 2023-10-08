class Solution {
public:
    
    int f(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        //If nothing is picked only siu
        
        if(i>=nums1.size() && j==0){
            return INT_MIN;
        }
        if(i>=nums1.size() || j>=nums2.size()){
            return 0; //NO more siu
        }
        
        int sum=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //two choices pick or notpick
        
        int notpick=f(i+1,j,nums1,nums2,dp);
        
        int pick=INT_MIN;
        
        for(int idx=j;idx<nums2.size();++idx){
            int temp=nums1[i]*nums2[idx];
            pick=max(pick,f(i+1,idx+1,nums1,nums2,dp)+temp);
        }
        //Bhai how xD
        
        return dp[i][j]=max(pick,notpick);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        //I am a god :D
        
        //Have to go forward Siuuuu
        
        int n=nums1.size();
        int m=nums2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return f(0,0,nums1,nums2,dp);
    }
};