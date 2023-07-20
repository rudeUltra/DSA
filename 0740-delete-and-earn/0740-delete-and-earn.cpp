class Solution {
public:
   int dp[10001];
    int houseRobber(vector<int>& arr, int idx){
        if(idx>=arr.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max(arr[idx]+houseRobber(arr,idx+2),houseRobber(arr,idx+1));
    }
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        vector<int> a(10001,0);
        for(auto num : nums) a[num] += num;
        return houseRobber(a,0);
    }
};