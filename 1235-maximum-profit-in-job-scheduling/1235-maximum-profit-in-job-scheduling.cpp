class Solution {
private: int N, memo[1000001];
private:
    int dfs(vector<vector<int>>&nums, int idx){
        if(idx >= N) return 0;
        if(memo[idx]) return memo[idx];
        int lo = 0, hi = N - 1, newJobTime = N + 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(nums[mid][0] >= nums[idx][1]) newJobTime = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        return memo[idx] = max(dfs(nums, idx + 1), nums[idx][2] + dfs(nums, newJobTime));
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        N = size(profit);
        vector<vector<int>> nums;
        for(int i = 0; i < N; ++i) nums.push_back({startTime[i], endTime[i], profit[i]});
        sort(begin(nums), end(nums));
        return dfs(nums, 0);
    }
};