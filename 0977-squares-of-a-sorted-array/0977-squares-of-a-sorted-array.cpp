class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0;
        int k=nums.size()-1;
        int right=nums.size()-1;
        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;--i){
            if(abs(nums[left])>abs(nums[right])){
                ans[i]=nums[left]*nums[left];
                left++;
            }
            else{
                ans[i]=nums[right]*nums[right];
                right--;
            }
        }
        return ans;
    }
};