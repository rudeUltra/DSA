class Solution {
public:
    void dfs(int target,int k,vector<int>&temp,vector<vector<int>>&ans,int idx){
        if(target==0 && k==0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<=9;++i){
            if(i<=target){
                temp.push_back(i);
                dfs(target-i,k-1,temp,ans,i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        
        dfs(n,k,temp,ans,1);
        
        return ans;
    }
};