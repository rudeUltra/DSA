class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //USE the indexses siu
        for(int i=0;i<nums.size();++i){
            int temp=abs(nums[i]);
            if(nums[temp-1]<0){
                return temp;
            }
            nums[temp-1]=-nums[temp-1];
        }
        return 1;
    }
};