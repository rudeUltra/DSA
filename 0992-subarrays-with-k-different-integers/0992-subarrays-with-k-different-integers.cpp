class Solution {
public:
    int atMost(vector<int>& nums, int goal)
    {
        unordered_map<int,int>mp;
        int window_start=0, window_end=0, ans=0,count=0;
        if (goal < 0)
            return 0;
        for(window_end=0; window_end<nums.size() ;window_end++)
        {
            mp[nums[window_end]]++;
            while(mp.size()>goal)
            {
                mp[nums[window_start]]--;
                if(mp[nums[window_start]]==0)
                    mp.erase(nums[window_start]);
                window_start++;
            }
            ans+=window_end-window_start+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};