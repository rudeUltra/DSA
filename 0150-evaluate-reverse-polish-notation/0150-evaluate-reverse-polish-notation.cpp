class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //its postfix lmao
        stack<long long>st;
        int n=tokens.size();
        for(int i=0;i<n;++i){
            if(tokens[i]=="+"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(x+y);
            }
            else if(tokens[i]=="-"){
                  int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                //reverse order a-b since stack so b-a in addition and * we dont care order
                st.push(y-x);
            }
            else if(tokens[i]=="*"){
                long long x=st.top();
                st.pop();
                long long y=st.top();
                st.pop();
                long long temp=x*y;
                st.push(temp);
            }
            else if(tokens[i]=="/"){
                  int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                st.push(y/x);
            }
            else{
                
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
        
    }
};