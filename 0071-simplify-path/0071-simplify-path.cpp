class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        stack<string>st;
        path=path+"/";
        string curr="";
        for(int i=0;i<n+1;++i){
            if(path[i]=='/'){
                if(curr==".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }
                else if(curr!="" && curr!="."){
                    st.push(curr);
                }
                curr="";
            }
            else{
                curr=curr+path[i];
            }
        }
        string ans;
        //reverse stack
        
        stack<string>st2;
        
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        ans="/"+ans;
        while(!st2.empty()){
            ans=ans+st2.top();
            st2.pop();
            if(!st2.empty()){
                ans=ans+"/";
            }
            
        }
        return ans;
        
    }
};