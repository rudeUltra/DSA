class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_dist=0;
        
        for(int i=0;i<n;++i){
            if(i>max_dist){
                return false;
            }
            max_dist=max(max_dist,nums[i]+i);
        }
        return true;
    }
};