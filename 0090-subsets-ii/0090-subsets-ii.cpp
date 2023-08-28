class Solution {
public:
    
    void dfs(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        
        ans.push_back(temp);
        
        int prev=-11;
        for(int i=idx;i<nums.size();++i){
            cout<<nums[i]<<" ";
            if(nums[i]!=prev){
                temp.push_back(nums[i]);
                dfs(i+1,nums,temp,ans);
                temp.pop_back();
            }
            prev=nums[i];
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 1 2 2 3 3
        //basically check in the same for loop did it already occur or not
        //if it did then for that possibility ending with that number we have already explored OOh
        //imp thing is in thAt for loop not idx-1 OOOoh
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        dfs(0,nums,temp,ans);
        
        return ans;
    }
};