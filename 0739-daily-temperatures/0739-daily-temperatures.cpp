class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //jUst show up everyday that's what matters Hm.
        int n=temperatures.size();
        stack<int>st;
        vector<int>nextGreater(n,0); //hM.
        
        for(int i=0;i<n;++i){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                nextGreater[st.top()]=i-st.top(); //Diff in indexes Hm.
                st.pop();
            }
            st.push(i);
        }
        
        return nextGreater;
    }
};