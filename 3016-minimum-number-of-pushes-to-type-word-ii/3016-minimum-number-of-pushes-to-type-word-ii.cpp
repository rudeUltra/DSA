class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        unordered_map<char,int>mp;
        
        for(int i=0;i<n;++i){
            mp[word[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        //8 available keyPads Hm.
        int cost=0;
        int curr=1;
        int level=0;
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            cout<<curr<<" "<<endl;
            cost+=(curr*it.first);
            level++;
            if(level==8){
                level=0;
                curr++;
            }
        }
        
        return cost;
    }
};