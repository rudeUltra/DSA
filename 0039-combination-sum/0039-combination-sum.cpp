class Solution {
public:
    
    void f(int idx,vector<int>&candidates,int target,vector<int>&temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx==candidates.size()){
            return;
        }
        //Notpick
        f(idx+1,candidates,target,temp,ans);
        //Pick
        if(candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            f(idx,candidates,target-candidates[idx],temp,ans);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        
        f(0,candidates,target,temp,ans);
        
        return ans;
    }
};