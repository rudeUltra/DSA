class Solution {
public:
    
    // our answer depends on the number of Zeroes present between two adjacent Ones.
    
    int mod = 1e9+7;
    
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> p(n, 0);      //array to store positions of 1
        int ind = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i] == 1){     // store the position of 1
                p[ind] = i;
                ind++;
            }
        }
        
        if(ind==0)    return 0;     //edge case when there is no 1 present in nums
        
        long long cntWays = 1;   //otherwise one way always exist
        
        for(int i=0;i<ind-1;i++){
            cntWays = (cntWays * (p[i+1] - p[i]))%mod;    // multiply the ways with the number of zeroes between adjacent 1's,
        }
        return cntWays;
        
    }
};