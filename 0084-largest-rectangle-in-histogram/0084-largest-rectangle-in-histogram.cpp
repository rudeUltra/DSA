class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //we traverse till n because have to take care of remaining elements in the stack SIUU

        //Optimised version of left smaller and right smaller we know the right smaller using 1 stack INcreasing order

        //for the left smaller we will use the second element of the stack since its an increasing stack Siuuu

        //Before popping each element try finding its area right smaller will be the i or the current element

        //dont go to each element but when popping same concept How can i HELP U :) when we find the next smaller try finding areas of all the heights before popping them and store the ans

        //edge case would be after the iteration some elements would be remaining in the stack so take care of them their area also

        int n=heights.size();
        int ans=INT_MIN;
        stack<int>st;
        for(int i=0;i<=n;++i){
            while(!st.empty() && (i==n || heights[st.top()]>heights[i])){
                //maintain increasing order
                int height=heights[st.top()];
                st.pop();
                int width=0;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1; //st.top represent the other element not popping just taking the value OOh
                }
                

                int area=width*height;
                ans=max(ans,area);
            }
            st.push(i);
        }
        return ans;
    }
};