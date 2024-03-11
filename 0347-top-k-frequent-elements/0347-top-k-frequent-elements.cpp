class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //min heap to maintain K size hm
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(pq.size()<k){
                pq.push({it.second,it.first});
            }
            else{
                //Hm.
                if(pq.top().first<it.second){
                    //Or i can just check with a normal if else ok anyway.
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
        }
        
        //AAHa noice
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        
        return ans;
    }
};