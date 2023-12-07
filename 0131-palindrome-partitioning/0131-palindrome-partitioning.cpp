class Solution {
public:
    bool isPal(string &temp){
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
    void f(int idx,string &s,vector<string>&temp,vector<vector<string>>&ans){
        if(idx==s.size()){
            ans.push_back(temp);
            return;
        }
        string temp1="";
        for(int i=idx;i<s.size();++i){
            temp1+=s[i];
            if(isPal(temp1)){
                temp.push_back(temp1);
                f(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
        
    }
    
    //Lets Gooo \U0001f60e
    
    vector<vector<string>> partition(string s) {
        //I legit need to host my sites BC..
        //let's do that only today let's host Kuebiko Siu
        //Explore CHakraUI
        
        vector<string>temp;
        vector<vector<string>>ans;
        
        int n=s.size();
        
        f(0,s,temp,ans);
        
        return ans;
        
        
    }
};