class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<int>st;
        for(int i=0;i<n;++i){
            while(!st.empty() && heights[i]<heights[st.top()]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && heights[i]<heights[st.top()]){
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            int temp=(right[i]-left[i])-1;
            ans=max(ans,heights[i]*temp);
        }
        return ans;
    }
};