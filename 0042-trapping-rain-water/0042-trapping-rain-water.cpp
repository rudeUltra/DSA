class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>maxleft(n);
        vector<int>maxright(n); //precompute

        int mn=INT_MIN;
        for(int i=0;i<n;++i){
            mn=max(mn,height[i]);
            maxleft[i]=mn;
        }

        mn=INT_MIN;

        for(int i=n-1;i>=0;--i){
            mn=max(mn,height[i]);
            maxright[i]=mn;
        }
        //calculate amount of water for each block siu

        int ans=0;

        for(int i=0;i<n;++i){
            ans=ans+(min(maxright[i],maxleft[i])-height[i]);
        }

        //since most of the max values are repeating we try to duplicate the max values instead of storing them using two pointers

        //extra variables maxleft and maxright to assign max on the go dynamic instead of storing so saves a lot of time siu

        //using two pointer before taking the ans we have to guarentee that water can be stored check left or right greater or not siu

        return ans;
    }
};