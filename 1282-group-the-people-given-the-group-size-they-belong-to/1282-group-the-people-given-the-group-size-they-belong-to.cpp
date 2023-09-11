class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>mp;
        
        for(int i=0;i<groupSizes.size();++i){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto it:mp){
            int size=it.first;
            vector<int>temp=it.second;
            
            if(temp.size()<=size){
                ans.push_back(temp);
            }
            else{
                vector<int>temp2;
                for(int i=0;i<temp.size();++i){
                    temp2.push_back(temp[i]);
                    if(temp2.size()==size){
                        ans.push_back(temp2);
                        temp2.clear();
                    }
                }
            }
        }
        
        return ans;
    }
};