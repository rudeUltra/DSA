class Solution {
public:
    
    void f(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        ans.push_back(temp); //Push all xD
        int prev=-11;
        for(int i=idx;i<nums.size();++i){
            if(nums[i]!=prev){
                temp.push_back(nums[i]);
                f(i+1,nums,temp,ans);
                temp.pop_back();
            }
            prev=nums[i];
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //Starting with this index find me all subsets siu
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        f(0,nums,temp,ans);
        
        return ans;
    }
};