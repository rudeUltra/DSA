class Solution {
public:
    
    void f(int open,int close,int n,vector<string>&ans,string temp){
        if(open==n && close==n){
            //done 
            ans.push_back(temp);
            return;
        }
        
        if(open<n){
            f(open+1,close,n,ans,temp+'(');
        }
        if(close<open){
            f(open,close+1,n,ans,temp+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        //Decision making 
        //Drop rain hm
        vector<string>ans;
        f(0,0,n,ans,"");
        
        return ans;
    }
};