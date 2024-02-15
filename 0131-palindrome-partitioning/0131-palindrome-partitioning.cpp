class Solution {
public:
    
    bool isPal(string &curr){
        int n=curr.size();
        int i=0;
        int j=n-1;
        
        //2 pointers hm.
        while(i<j){
            if(curr[i]!=curr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void f(int idx,string&s,vector<string>&temp,vector<vector<string>>&ans){
        if(idx>=s.size()){
            //Noice
            ans.push_back(temp);
            return;
        }
        string curr="";
        for(int i=idx;i<s.size();++i){
            curr+=s[i]; //make the new substring
            
            if(isPal(curr)){
                temp.push_back(curr);
                f(i+1,s,temp,ans);
                temp.pop_back(); //backtrack Hm.
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        
        f(0,s,temp,ans);
        
        return ans;
    }
};