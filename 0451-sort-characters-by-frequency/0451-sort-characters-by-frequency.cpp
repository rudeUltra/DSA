class Solution {
public:
    string frequencySort(string s) {
       //priority queue boii
        priority_queue<pair<int,char>>pq;
        //spelling bc
        unordered_map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;++i){
            mp[s[i]]++;
        }
        //map to get the frequency siu
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            auto it=pq.top();
            char c=it.second;
            int count=it.first;
            while(count){
                ans+=c;
                count--;
            }
            pq.pop();
        }
        return ans;
    }
};