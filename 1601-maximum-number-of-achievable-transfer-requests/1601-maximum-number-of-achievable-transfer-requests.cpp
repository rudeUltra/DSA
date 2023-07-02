class Solution {
public:
    void dfs(int idx,vector<vector<int>>&requests,vector<int>&indegree,int &ans,int count){
        if(idx==requests.size()){
            //sed left
            
            for(int i=0;i<indegree.size();++i){
                if(indegree[i]!=0){
                    //noice 
                    return; //invalid
                }
            }
            
            ans=max(ans,count);
            return;
            
            
        }
        
        indegree[requests[idx][0]]--;
        indegree[requests[idx][1]]++;
        dfs(idx+1,requests,indegree,ans,count+1);
        //backtrack
        
        indegree[requests[idx][0]]++;
        indegree[requests[idx][1]]--;
        
        dfs(idx+1,requests,indegree,ans,count);
        
    }
    
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        //big mistake by us not checking the constraints
        //very less constraints meaning it was backtracking sed anyway moving on
        //we though of greedy and indegree outdegree works in this case but not for all so 
        //again keep in mind the time constraint gg
        
        vector<int>indegree(n,0); //ok net 0 so +- on the same array hm
        
        int ans=0;
        dfs(0,requests,indegree,ans,0);
        
        return ans;
    }
};