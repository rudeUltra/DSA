class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        int res=1;
        for(int i=0;i<n;++i){
            ans[i]=res;
            res=res*nums[i]; //calculating prefix
        }
        res=1;
        for(int i=n-1;i>=0;--i){
            ans[i]=ans[i]*res;
            res=res*nums[i];
        }
        return ans;
    }
};