class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //basically kind of greedy plus sliding window but lets go siu
        int n=nums.size();
        int left=0;
        int right=0;
        int count=k;
        int ans=0;
        while(right<n){
            if(nums[right]==1){
                ans=max(ans,(right-left+1));
                right++;
            }
            else if(nums[right]==0 && count>0){
                count--;
                ans=max(ans,(right-left+1));
                right++;
            }
            else{
                //not valid
                if(nums[left]==0){
                    count++;
                }
                left++;
            }
        }
        
        return ans;
    }
};