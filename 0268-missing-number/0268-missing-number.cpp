class Solution {
public:
      int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i=0;i<=n;i++){
            x ^= i; //take the whole xor imagine as 1 2 3 4 5
        }
        
        for(int i=0;i<n;i++){
            x^= nums[i]; //keep crossing off numbers 1 3 4 5...
        }
        
        return x;
    }
};