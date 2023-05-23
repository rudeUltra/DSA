class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //lets implement 2 solution 1 reverse 2 is brute force rotate hm
        
        int n=nums.size();
        k=k%n;
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};