class Solution {
public:
    
    
    
    //Basically glorified pick not pick NoICe
    
    void f(vector<int>&candidates,int idx,int target,vector<vector<int>>&ans,vector<int>&temp){
        if(target==0){
            //gotemm
            ans.push_back(temp);
            return;
        }
        
        if(idx>=candidates.size()){
            return; //Moye Moye.
        }
        
        //not pick
        f(candidates,idx+1,target,ans,temp);
        
        //Pick
        if(candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            f(candidates,idx,target-candidates[idx],ans,temp);
            temp.pop_back(); //backTrack Noice
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();
        
        f(candidates,0,target,ans,temp);
        
        return ans;
    }
};