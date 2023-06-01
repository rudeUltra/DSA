class Solution {
public:
    string reverseWords(string s) {
        //lets try with stck first gg ez
        stack<string>st;
        int n=s.length();
        int i=0;
        
        while(i<n){
            int j=i;
            while(j<n && s[j]==' '){
                ++j;
            }
            string temp="";
            while(j<n && s[j]!=' '){
                temp+=s[j];
                ++j;
            }
            if(temp.length()!=0){
                 st.push(temp);
            }
           
            i=j;
        }
        
        string ans="";
        while(!st.empty()){
            
            if(st.size()==1){
                //last word so no space
                ans+=st.top();
             
            }
            else{
                ans+=st.top()+" ";
                
            }
            st.pop();
        }
        return ans;
    }
};