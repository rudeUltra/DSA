class Solution {
public:
    
    void dfs(string node,string dest,unordered_map<string,vector<pair<string,double>>>&mp,unordered_map<string,int>&visited,vector<double>&ans,double value,bool &flag)    
    {
        
        visited[node]=1;
        
        if(node==dest){
            flag=0;
            ans.push_back(value);
            return;
        }
        
        for(auto it:mp[node]){
            if(visited[it.first]!=1){
                //not visited go ahead siu
                dfs(it.first,dest,mp,visited,ans,value*it.second,flag);
            }
        }
        
      
        
        
        
    }
    
    
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        //normal adj list wont work we need a map hm since characters
        unordered_map<string,vector<pair<string,double>>>mp; //modified adj list
        
        for(int i=0;i<equations.size();++i){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1/values[i]});
          
        }
        
        //perform dfs hm
        
        vector<double>ans;
        
        unordered_map<string,int>visited; //clear the map after each dfs hm
        for(int i=0;i<queries.size();++i){
            string src=queries[i][0];
            string dest=queries[i][1];
            
            if(mp.find(src)==mp.end() || mp.find(dest)==mp.end()){
                //src or destination not present in the graph sed
                ans.push_back(-1);
                continue;
            }
            
            if(mp.find(src)!=mp.end() && src==dest){
                //hm
                ans.push_back(1);
                continue;
            }
            
            //dfs time boi
            bool flag=1;
            dfs(src,dest,mp,visited,ans,1,flag);
            visited.clear();
            if(flag==1){
                ans.push_back(-1);
            }
        }
        
        return ans;
            
    }
};