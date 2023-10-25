class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n,-1);
        vector<int>right(n,-1); //-1 bcus we need both left and right to store the water so siu
        
        int mx=INT_MIN;
        
        for(int i=0;i<n;++i){
            mx=max(mx,height[i]);
            left[i]=mx;
        }
        mx=INT_MIN;
        for(int i=n-1;i>=0;--i){
            mx=max(mx,height[i]);
            right[i]=mx;
        }
        int total=0;
        
        for(int i=0;i<n;++i){
            int h=min(left[i],right[i]);
            h=h-height[i];
            total+=h;
        }
       
        
        return total;
    }
};