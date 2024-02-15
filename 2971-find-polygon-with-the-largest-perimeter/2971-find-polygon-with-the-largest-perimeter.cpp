class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        long long ans=-1;
        long long sum=0; //prefix sum nOice
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;++i){
         
            if(i>1){
                //mInimum length 3 Hm potential ans maybe
                if(nums[i]<sum){
                    ans=sum+nums[i]; //aHA
                }
            }
            sum+=nums[i];
        }
        
        return ans;
    }
};