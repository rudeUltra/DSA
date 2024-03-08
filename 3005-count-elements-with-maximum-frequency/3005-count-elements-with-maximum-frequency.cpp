class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int max_freq=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            max_freq=max(max_freq,it.second);
        }
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(mp[nums[i]]==max_freq){
                ans++;
            }
        }
        return ans;
    }
};