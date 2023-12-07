class Solution {
public:
    
    
    void f(vector<int>&nums,unordered_map<int,int>mp,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();++i){
            if(mp[i]==0){
                //take indexes not elements hm
                mp[i]=1;
                temp.push_back(nums[i]);
                f(nums,mp,temp,ans);
                temp.pop_back(); //backtrack
                mp[i]=0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        //2 ways either swap or map we use map xD
        //Trick is to use for loop always from the starting index
        
        //Jamal kudul vibe hai xD
        unordered_map<int,int>mp;
        vector<int>temp;
        vector<vector<int>>ans;
        
        f(nums,mp,temp,ans);
        
        return ans;
    }
};