class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //If we have figured out O(n) try nlogn ? Wow.
        
        int n=nums.size();
        int left=0;
        int right=0;
        
        int sum=0;
        
        //mInIMAL bOiii
        int ans=INT_MAX;
        
        while(right<n && left<=right){
            sum+=nums[right];
            
            //check Invalid Gotemm
            while(sum>=target){
                ans=min(ans,(right-left)+1);
                sum-=nums[left];
                left++;
                
            } 
            
            right++;
        }
        
        return ans==INT_MAX?0:ans;
    }
};