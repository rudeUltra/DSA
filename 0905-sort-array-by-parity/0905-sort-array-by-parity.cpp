class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        
        while(left<right){
            while(left<right && nums[left]%2==0){
                left++;
            }
            while(left<right && nums[right]%2==1){
                right--;
            }
            
            if(left<right){
                //Swap left and right
                int temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
            }
        }
        return nums;
    }
};