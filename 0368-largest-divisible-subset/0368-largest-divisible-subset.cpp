class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1); //1 because every element is a subsequence in itself
        vector<int>hash(n);
        int last=0; //for tracking back and printing the ans
        int mx=INT_MIN; //for finding the max length
        for(int i=0;i<n;++i){
            hash[i]=i;
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    //checking dp[j]+1>dp[i bcus we wanna know the max we cant update randomly siu]
                    dp[i]=dp[j]+1;
                    hash[i]=j; //storing prev index for backtracking and printing the ans siu
                }
            }
            if(dp[i]>mx){
                mx=dp[i];
                last=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};