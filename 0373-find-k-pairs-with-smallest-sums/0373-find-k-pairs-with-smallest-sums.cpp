class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

    vector<vector<int>> res;
   
    priority_queue<pair<int,pair<int,int>>> pq;
    
    for(auto x:nums1){
        for(auto y:nums2){
            int sum=x+y;
            if( pq.size()<k){
                 pq.push({sum,{x,y}});
            }
            else if(sum < pq.top().first)
            {
                pq.pop();
                pq.push({sum,{x,y}});
            }
            else
                break; //we maintain a k sized heap to reduce the time complexity siu
        }
    }
    
    while(!pq.empty() ){
       auto p=pq.top().second;
        pq.pop();
        
        res.push_back({p.first,p.second});
    }
    return res;
}
};