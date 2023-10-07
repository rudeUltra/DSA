class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<string>st; //to store indexes
        int n=s.size();
        string ans="";

        for(int i=0;i<n;++i){
            if(s[i]=='('){
                //2 conditions either outer bracket or inner

                if(st.size()!=0){
                    //inner bracket so part of the ans
                    ans.push_back('(');
                }
                st.push("(");
            }
            else{
                //closing bracket 
                if(st.size()>1){
                    ans.push_back(')');
                }
                st.pop();
            }
        }

        return ans;
    }
};