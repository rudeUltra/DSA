class Solution {
public:
    
    void f(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }
        f(idx+1,nums,temp,ans);
        temp.push_back(nums[idx]);
        f(idx+1,nums,temp,ans);
        temp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        //Siu
        //Basically pick or not pick siu
        vector<int>temp;
        vector<vector<int>>ans;
        //It will reach the end xD
        f(0,nums,temp,ans);
        
        return ans;
    }
};