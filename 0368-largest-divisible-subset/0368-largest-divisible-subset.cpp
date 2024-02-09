class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //transitive property if a-b b-c then a-c Noice
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n);
        
        for(int i=0;i<n;++i){
            hash[i]=-1;
        }
        int ans=0;
        int start=0;
        
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0){
                    //noice
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        ans=max(ans,dp[i]);
                        hash[i]=j;
                    }
                }
            }
            if(dp[i]==ans){
                start=i;
            }
        }
        vector<int>ans1;
        ans1.push_back(nums[start]);
        while(start>=0 && hash[start]!=-1){
            start=hash[start];
            ans1.push_back(nums[start]);
            
        }
        
        return ans1;
        
        
        
    }
};