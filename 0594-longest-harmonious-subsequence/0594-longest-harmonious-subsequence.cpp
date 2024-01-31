class Solution {
public:
    int findLHS(vector<int>& nums) {
        //All hards BC aYYo.
        
        sort(nums.begin(),nums.end());
        int ans=0;
        for(auto it:nums){
            cout<<it<<" "; 
        }
        int left=0;
        int right=1;
        
        int n=nums.size();
        
        while(right<n && left<=right){
            if(abs(nums[right]-nums[left])>1){
                
                left++;
            }
            else{
                if((nums[right]-nums[left])==1){
                    ans=max(ans,(right-left+1));
                }
                right++;
            }
        }
        
        return ans;
    }
};