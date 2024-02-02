class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        
        for(int i=0;i<n;++i){
            mp[s[i]]++;
        }
        
        priority_queue<pair<int,char>>pq;
        
        //Show them eleven.
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        string ans="";
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            char c=it.second;
            int limit=0;
            while(limit<it.first){
                ans+=c;
                limit++;
            }
        }
        
        return ans;
    }
};