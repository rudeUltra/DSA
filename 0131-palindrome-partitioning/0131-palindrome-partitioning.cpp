class Solution {
public:
    bool isValid(string temp){
        int i=0;
        int j=temp.size()-1;
        
        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    void f(int idx,string s,vector<vector<string>>&ans,vector<string>&temp){
        if(idx==s.size()){
            ans.push_back(temp);
            return;
        }
        //if no palindrome then dont worry single character case will be handled siu
        for(int i=idx;i<s.size();++i){
            string temp2=s.substr(idx,(i-idx+1));
            if(isValid(temp2)){
                temp.push_back(temp2);
                f(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        //Forward partition siu
        f(0,s,ans,temp);
        
        return ans;
    }
};