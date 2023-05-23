class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }
        int left=0;
        for(int i=1;i<n;++i){
            if(nums[left]!=nums[i]){
                nums[++left]=nums[i];
            }
        }
        return left+1;
    }
};