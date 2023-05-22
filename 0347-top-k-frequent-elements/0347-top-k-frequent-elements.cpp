class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //max-heap boi
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        //heap will be based on the frequency
        
        vector<int>ans;
        while(!pq.empty() && k>0){
            ans.push_back(pq.top().second);
            k--;
            pq.pop();
        }
        
        return ans;
    }
};