class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //siuu 3 for loops
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]<0){
                nums[i]=0;
            }
        }
        //marking the elements present in the array so they cannot be the ans siu
        
        for(int i=0;i<n;++i){
            //check for out of bounds range
            int val=abs(nums[i]);
            if(val>=1 && val<=n){
                if(nums[val-1]>0){
                    nums[val-1]=-1*nums[val-1];
                }
                else if(nums[val-1]==0){
                    nums[val-1]=-1*(n+1);
                    //can never be the ans lol
                }
            }
        }
        
        for(int i=1;i<n+1;++i){
            if(nums[i-1]>=0){
                return i;
            }
        }
        //worst case
        return n+1;
    }
};