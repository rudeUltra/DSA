class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>ans;
        unordered_map<string,multiset<string>>mp; //fOR Sortec
        
        for(int i=0;i<tickets.size();++i){
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        
        //Stack so we can come back after travelling siu
        stack<string>st;
        
        st.push("JFK");
        
        while(!st.empty()){
            string curr=st.top();
            if(mp[curr].size()==0){
                ans.push_back(curr);
                st.pop();
            }
            else{
                auto it=mp[curr].begin();
                     st.push(*it);
                     mp[curr].erase(it);
                
                
            }
           
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
        
    }
};