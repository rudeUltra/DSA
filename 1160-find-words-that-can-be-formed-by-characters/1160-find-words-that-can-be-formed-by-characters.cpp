class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp1;
        
        for(int i=0;i<chars.size();++i){
            mp1[chars[i]]++;
        }
      
        int count=0;
        for(int i=0;i<words.size();++i){
            unordered_map<char,int>mp2;
            bool flag=1;
            for(int j=0;j<words[i].size();++j){
                mp2[words[i][j]]++;
            }
            
            for(auto it:mp2){
                
                if(mp1[it.first]==0 || mp1[it.first]<it.second){
                    flag=0;
                }
            }
            if(flag){
                count=count+words[i].size();
            }
        }
        return count;
    }
};