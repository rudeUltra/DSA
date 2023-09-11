class Solution {
public:
    
    void f(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,unordered_map<int,int>mp){
        if(temp.size()==nums.size()){
            //All in
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(mp[i]==0){
                mp[i]++; //Use indexsed not numbers duplicates siu
            temp.push_back(nums[i]);
            f(nums,temp,ans,mp);
                temp.pop_back();
                mp[i]=0;
                
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        //Permutation Hm
        //BC XD
        unordered_map<int,int>mp;
        vector<int>temp;
        vector<vector<int>>ans;
        //No concept of idx because we have to come to the beginning evert time siu
        
        f(nums,temp,ans,mp);
        
        return ans;
    }
};