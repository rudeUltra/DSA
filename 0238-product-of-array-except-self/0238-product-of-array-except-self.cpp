class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Kind of prefix sum xD ok 
        int n=nums.size();
        vector<int>ans(n,0);
        int sum=1;
        
        for(int i=0;i<n;++i){
            ans[i]=sum*nums[i];
            sum=sum*nums[i];
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        sum=1;
        for(int i=n-1;i>=0;--i){
            if(i==0){
                ans[i]=sum;
            }
            else{
                int prev=ans[i-1];
                ans[i]=prev*sum;
                sum=sum*nums[i];
            }
        }
        return ans;
    }
};