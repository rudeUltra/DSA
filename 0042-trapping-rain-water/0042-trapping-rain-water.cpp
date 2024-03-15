class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int mx=height[0];
        left[0]=mx;
        for(int i=1;i<n;++i){
            mx=max(height[i],mx);
            left[i]=mx; //Max height till here hM.
        }
        mx=INT_MIN;
        for(int i=n-1;i>=0;--i){
            mx=max(height[i],mx);
            right[i]=mx;
        }
        
       //Now calculate hm.
        int ans=0;
        
        for(int i=0;i<n;++i){
            int h=min(left[i],right[i]);
            ans=ans+(h-height[i]);
        }
        return ans;
        
    }
};