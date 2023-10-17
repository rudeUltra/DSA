class Solution {
public:
    
    bool dfs(int node,vector<int>&visited,vector<int>&path,vector<int>adj[],vector<int>&count){
        visited[node]=1;
        path[node]=1;
        
        for(auto it:adj[node]){
            count[it]++;
            if(visited[it]==0){
                if(dfs(it,visited,path,adj,count)){
                    return true; //Cycle
                }
            }
            else if(visited[it]!=0 && path[it]==1){
                return true;
            }
            
        }
        
        //Explored this path so siuu
        path[node]=0;
        return false;
    }
    
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //looks doable siUUU
        
        vector<int>adj[n];
        
        for(int i=0;i<n;++i){
            if(leftChild[i]!=-1){
             adj[i].push_back(leftChild[i]);
            }
            if(rightChild[i]!=-1){
                 adj[i].push_back(rightChild[i]);
            }
           
        }
        
        //Single component + No cycles siu
        
        vector<int>visited(n,0);
        vector<int>path(n,0);
        vector<int>count(n,0);
        int count2=0;
        for(int i=0;i<n;++i){
            
           if(visited[i]==0 && count2!=0){
               if( leftChild[i]!=-1 && visited[leftChild[i]]==0 && rightChild[i]!=-1 && visited[rightChild[i]]==0){
                   return false;
               }
               if(dfs(i,visited,path,adj,count)){
                    return false;
                }
               
           }
            if(visited[i]==0){
                count2++;
                if(dfs(i,visited,path,adj,count)){
                    return false;
                }
               
            }
        }
        int zeroRoot=0;
        for(int i=0;i<n;++i){
            if(count[i]==0){
                zeroRoot++;
            }
            if(count[i]>1){
                return false;
            }
        }
        if(zeroRoot>1){
            return false;
        }
        return true;
    }
};