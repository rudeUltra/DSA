class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>count(32,0);
        int n=nums.size();
        
        for(int i=0;i<32;++i){
            for(int j=0;j<n;++j){
                if(nums[j] & 1<<i){
                    count[i]=count[i]+1;
                }
            }
        }
        unsigned res=0;
        for(int i=0;i<32;++i){
            res=res+(count[i]%3)*(1<<i);
        }
        
        return res;
    }
};