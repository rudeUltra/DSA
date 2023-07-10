class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& in, vector<int>& queries) {
        
        //sort the intervals
        //sort the query
        sort(in.begin(),in.end());
        
        //store the indices along with the values
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++)
        {
            q.push_back({queries[i],i});
        }
        
        sort(q.begin(),q.end());
        
        vector<int> res(q.size());
        //use min heap
        using pi=pair<int,int>;
        //pi.first stores the size of interval
        //pi.second stores the ending value of interval
        
        //min heap
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        
        int i=0,len=in.size();
        //for every query insert the possible intervals in which the query lies 
        //into min heap

        
        for(int j=0;j<q.size();j++)
        {
            auto[val,ind]=q[j];
            
            while(i<len && in[i][0]<=val)
            {
                pq.push({in[i][1]-in[i][0] +1 , in[i][1]});
                i++;
            }
            
            //pop out the intervals in minHealw which doesnot include the current  val
            while(!pq.empty() && pq.top().second<val)
                pq.pop();
            
            res[ind]=(pq.empty()) ? -1 : pq.top().first;
                
        }
        
        return res;
        
    }
};