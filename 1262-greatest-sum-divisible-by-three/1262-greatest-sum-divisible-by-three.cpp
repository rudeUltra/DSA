class Solution {
public:
    int fun(int idx , vector<int>& nums , int curr_sum_rem , vector<vector<int>>& dp){
        // base case
        if(idx >= nums.size()){
            if(curr_sum_rem == 0)
                return 0;
            return INT_MIN;
        }

        // memoization.....
        if(dp[idx][curr_sum_rem] != -1)
            return dp[idx][curr_sum_rem];

        int take = nums[idx] + fun(idx+1 , nums ,(curr_sum_rem+nums[idx])%3 , dp);
        int notTake = fun(idx+1 , nums , curr_sum_rem , dp);

        return dp[idx][curr_sum_rem] = max(take , notTake);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(3 , -1));
        return fun(0 , nums , 0 , dp);
    }
};