class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.size();
        if(s==goal){
            unordered_map<int,int>mp;
            for(int i=0;i<n;++i){
                mp[s[i]]++;
                if(mp[s[i]]>1){
                    return true;
                }
            }
            return false;
        }
        if(n!=goal.size()){
            return false;
        }
        int count=0; //2 poisitions bad xD
        int first=-1;
        int second=-1;
        for(int i=0;i<n;++i){
           if(s[i]!=goal[i] && count==0){
               count++;
               first=i;
           }
            else if(s[i]!=goal[i] && count==1){
                count++;
                second=i;
            }
            else if(s[i]!=goal[i] && count==2){
                return false; //more than 2 bad sed
            }
        }
        if(count==1){
            return false;
        }
        
        if(goal[first]==s[second] && s[first]==goal[second]){
            return true;
        }
        
        return false;
    }
};