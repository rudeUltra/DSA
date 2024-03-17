class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        int n=points.size();
        
        for(int i=0;i<n;++i){
            int x=pow(points[i][0],2);
            int y=pow(points[i][1],2);
            int temp=x+y;
            cout<<temp;
            pq.push({-temp,i}); //min heap bc
        }
        
        vector<vector<int>>ans;
        for(int i=0;i<k;++i){
            cout<<pq.top().first;
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};