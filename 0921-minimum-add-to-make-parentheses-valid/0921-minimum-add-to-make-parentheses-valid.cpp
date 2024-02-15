class Solution {
public:
    int minAddToMakeValid(string s) {
        //Every opening should have a closing brecket NOice
        int n=s.size();
        stack<char>st;
        int count=0;
        for(int i=0;i<n;++i){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(!st.empty()){
                    st.pop(); //match match
                }
                else{
                    count++;
                }
            }
        }
        
        //Check for remaining opening brackets which are not satisfied Sed. nvm
        
        return count+st.size();
    }
};