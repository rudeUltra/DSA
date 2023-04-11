class Solution {
public:
    string removeStars(string s) {
        //elimination so obvs stack hm
        int n=s.size();
        //given in question when star comes pop will always be possible siu
        stack<char>st;
        
        for(int i=0;i<n;++i){
            if(s[i]=='*'){
                st.pop(); //siu
            }
            else{
                st.push(s[i]);
            }
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};