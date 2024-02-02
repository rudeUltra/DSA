class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int ans=0;
        
        stack<char>st;
        
        for(int i=0;i<n;++i){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                int x=st.size();
                ans=max(ans,x);
                st.pop();
            }
        }
        
        return ans;
    }
};