class Solution {
public:
     map<pair<int,int>,int>mp;
    
    int f(int idx,int target,vector<int>&nums){
        if(idx==nums.size() && target==0){
            return 1; //Count DP
        }
        if(idx==nums.size()){
            return 0;
        }
        
        if(mp.find({idx,target})!=mp.end()){
            return mp[{idx,target}];
        }
        
        int plus=f(idx+1,target-nums[idx],nums);
        int neg=f(idx+1,target+nums[idx],nums);
        
        
        return mp[{idx,target}]=plus+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
       
        
        
        return f(0,target,nums);
        
        
    }
};