class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        vector<int>vis(26,0); //visited array
        
        for(int i=0;i<n;++i){
            mp[s[i]]++;
        }
        
        stack<char>st;
        
        for(int i=0;i<n;++i){
            mp[s[i]]--;
            if(vis[s[i]-'a']==0){
                //have to take this char!
                while(!st.empty() && st.top()>s[i] && mp[st.top()]>0){
                    //more than 1 hm
                    vis[st.top()-'a']=0; //unvisit
                    st.pop();
                }
                st.push(s[i]);
                vis[s[i]-'a']=1; //current visited
            }
        }
        string ans="";
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};