class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int>ans;
        //So more soldiers more weak hUH CONTROVERsial but ok
        for(int i=0;i<n;++i){
            int count=0;
            for(int j=0;j<m;++j){
                if(mat[i][j]==1){
                    count++;
                }
            }
            pq.push({count,i});
        }
        
        while(!pq.empty() && k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};