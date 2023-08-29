class Solution {
public:
    void f(vector<int>&nums,vector<int>&used,vector<int>temp,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            //all the characters are in siu
            ans.push_back(temp);
            return;
        }
        
        //Start from beginnning thats the tricky part hm
        for(int i=0;i<nums.size();++i){
            if(used[i]==0){
                used[i]=1;
                temp.push_back(nums[i]);
                f(nums,used,temp,ans);
                temp.pop_back();
                used[i]=0;
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        //OH very Noice question hm
        int n=nums.size();
        vector<int>used(n,0);
        vector<int>temp;
        vector<vector<int>>ans;
        
        f(nums,used,temp,ans);
        return ans;
    }
};