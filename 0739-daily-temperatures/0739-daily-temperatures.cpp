class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Kiliye kiliye
        
        //moNoTonic Steck
        int n=temperatures.size();
        //This is basically next greater AAi
        vector<int>ans(n,0);
        
        stack<int>st;
        
        for(int i=0;i<n;++i){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                //gotemm
                ans[st.top()]=abs(st.top()-i);
                st.pop();
            }
            st.push(i);
        }
        
        return ans;
    }
};