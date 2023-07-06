class Solution {
public:
    
    
    void dfs(vector<int>&nums,vector<int>&temp,unordered_map<int,int>&mp,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(mp[i]==0){
                //not visited
                mp[i]=1;
                temp.push_back(nums[i]);
                dfs(nums,temp,mp,ans);
                temp.pop_back();
                mp[i]=0;
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        
        dfs(nums,temp,mp,ans);
        
        return ans;
    }
};