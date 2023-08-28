class Solution {
public:
    
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //sorting siuu to remove duplicates 
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        f(0,candidates,target,curr);
        return ans;
    }
    void f(int index,vector<int>&candidates,int target,vector<int>&curr){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        int temp=-1;
        for(int i=index;i<candidates.size();++i){
            if(candidates[i]<=target && candidates[i]!=temp){
                curr.push_back(candidates[i]);
                f(i+1,candidates,target-candidates[i],curr);
                curr.pop_back();
            }
            temp=candidates[i];
        }
    }
};


//1 2 2 2 5 t=5