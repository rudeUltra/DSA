class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int>st;
        
        for(int i=0;i<n;++i){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int j=st.top()+1;
                int k=i;
                st.pop();
                //reverse till here nOice
                while(j<k){
                    char temp=s[j];
                    s[j]=s[k];
                    s[k]=temp;
                    j++;
                    k--;
                }
                
            }
        }
        string ans="";
        for(int i=0;i<n;++i){
            if(s[i]!='(' && s[i]!=')'){
                ans.push_back(s[i]);
            }
        }
        
        return ans;
        
    }
};