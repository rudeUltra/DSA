class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adj; //multiset to keep list sorted
        vector<string>ans;
        int n=tickets.size();
        for(int i=0;i<n;++i){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string>st;
        st.push("JFK"); //always start from JFK given siu
        
        while(!st.empty()){
            string src=st.top();
            if(adj[src].size()==0){
                //no more paths so push it into the ans siu
                ans.push_back(src);
                st.pop();
            }
            else{
                //nodes left traverse them
                auto it=adj[src].begin();
                st.push(*it);
                adj[src].erase(it);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};