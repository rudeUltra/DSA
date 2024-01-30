class Solution {
public:
    bool isOperand(string c){
        if(c=="+" || c=="-" || c=="/" || c=="*"){
            return true;
        }
        
        return false;
    }
    
    
    
    int evalRPN(vector<string>& tokens) {
        //postFix conversion !? Hm.
        stack<int>st;
        int n=tokens.size();
        
        for(int i=0;i<n;++i){
            if(isOperand(tokens[i])){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                
                //guranteed 2 elements will be there hm
                string operand=tokens[i];
                
                if(operand=="+"){
                    st.push(x+y);
                }
                else if(operand=="-"){
                    st.push(y-x);
                }
                else if(operand=="/"){
                    st.push(y/x);
                }
                else{
                    st.push(x*y);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();
        
    }
};