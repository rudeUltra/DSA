class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        
        while(left<n && right<n){
            if(nums[right]!=0){
                int temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
                ++left;
                ++right;
            }
            else{
                right++;
            }
        }
    }
};