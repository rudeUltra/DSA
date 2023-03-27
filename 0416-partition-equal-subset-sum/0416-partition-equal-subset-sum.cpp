class Solution {
public:
    bool subset(int index,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0){
        return true;
    }
    if(index==0){
        //only one option take
        if(target==arr[0]){
            return true;
        }
        else{
            return false;
        }
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    bool notake=subset(index-1,target,arr,dp);
    bool take=false;
    if(arr[index]<=target){
        take=subset(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target]=take||notake; //or
     
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
      
       for(int i=0;i<n;++i){
           sum=sum+nums[i];
       }
        if(sum%2==1){
            return false;
        }
        else{
            //sum=20 if 10 is found other is 10 only xD logic
             vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
             if(subset(n-1,sum/2,nums,dp)){
                 return true;
             }
            else{
                return false;
            }
        }
    }
};