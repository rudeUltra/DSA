class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //hash + heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(pq.size()==0 || pq.size()<k){
                pq.push({it.second,it.first});
            }
            else{
                if(pq.top().first<it.second){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
            
        }
        vector<int>ans;
        while(!pq.empty() && k){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        //nlogK
        return ans;
        
        
        
    }
};