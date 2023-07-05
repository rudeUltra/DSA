class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // 1 1 0 1 0 1 1 1 1 1
        //dp or sliding window makes sense siu
        int n=nums.size();
        int count1=0;
        int count0=0;
        int ans=INT_MIN;
        
        int left=0;
        int right=0;
        while(right<n){
            if(nums[right]==1){
                count1++;
            }
            
            else{
                count0++;
            }
            
            while(count0>1){
                //invalid sEd
                if(nums[left]==0){
                    count0--;
                }
                else{
                    count1--;
                }
                left++;
            }
            
            ans=max(ans,(count1));
            
            right++;
            
        }
        
        return count1==n?n-1:ans;
    }
};