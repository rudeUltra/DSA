class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //basically pick not pick xD`
        vector<int>curr;
        f(0,candidates,target,curr);
        
        return ans;
    }
    
    void f(int index,vector<int>&candidates,int target,vector<int>&curr){
        
        if(index>=candidates.size()){
            return;
        }
        
        if(target==0){
            ans.push_back(curr);
            return;
        }
        //pick not pick
        
        if(candidates[index]<=target){
            curr.push_back(candidates[index]);
            f(index,candidates,target-candidates[index],curr);
            curr.pop_back();
        }
        f(index+1,candidates,target,curr);
    }
};