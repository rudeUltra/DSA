class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();//siUuUuUuU
        int k;
        int l;
        for( k=n-2;k>=0;--k){
            if(nums[k]<nums[k+1]){
                break;
            }
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            //find next greater element and swap
            for(l=n-1;l>k;--l){
                if(nums[l]>nums[k]){
                    break;
                }
            }
            //swap
            int temp=nums[k];
            nums[k]=nums[l];
            nums[l]=temp;
            int i=k+1;
            int j=n-1;
            while(i<j){
                //swap
                int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
                ++i;
                --j;
            }
            
        }
    }
};