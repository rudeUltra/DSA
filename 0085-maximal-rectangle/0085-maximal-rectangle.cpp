class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>rows(m,0);
        //traverse through each row
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]=='1'){
                    rows[j]++;
                }
                else{
                    rows[j]=0;
                }
            }
          
            int area=histogram(rows);
            ans=max(ans,area);
        }
        return ans;
    }
     int histogram(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int ans=0;
        //we traverse till n because have to take care of remaining elements in the stack SIUU
        for(int i=0;i<=n;++i){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                //big brain or condition xD
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                ans=max(ans,width*height);
            }
                  st.push(i);
        }
        return ans;
    }
};