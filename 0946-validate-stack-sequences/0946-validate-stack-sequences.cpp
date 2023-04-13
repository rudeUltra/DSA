class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int>st;
        int j=0;
        for(int i=0;i<n;++i){
            st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        
        if(st.size()!=0){
            return false;
        }
        
        return true;
    }
};