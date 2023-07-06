class Solution {
public:
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(),candidates.end()); //sort hmm important
        vector<vector<int>> ans;
        vector<int>current;
        backtrack(ans,current,candidates,target,0);
        return ans;
    }
    void backtrack(vector<vector<int>>&ans,vector<int>&current,vector<int>&candidates,int target,int idx){
        if(target==0){
            ans.push_back(current);
            return;
        }
        
        for(int i=idx;i<candidates.size() ;++i){
            if(candidates[i]<=target){
            current.push_back(candidates[i]);
            backtrack(ans,current,candidates,target-candidates[i],i);
            current.pop_back();
            }
        }
    }
    
    
};