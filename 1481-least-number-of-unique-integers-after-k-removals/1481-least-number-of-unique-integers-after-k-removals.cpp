class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //we want Min queue HM.
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;++i){
            mp[arr[i]]++;
        }
        
        //traversr through the map hm.
        
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        while(!pq.empty()){
            if(pq.top().first>k){
                //cant remove anymore sed
                break;
            }
            auto it=pq.top();
            pq.pop();
            k=k-it.first;
        }
        return pq.size();
    }
};