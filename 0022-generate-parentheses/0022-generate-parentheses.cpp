class Solution {
public:
    void f(int idx,int open,int close,string s,int n,vector<string>&ans){
        if(idx==2*n){
            ans.push_back(s);
            return;
        }
        
        if(open<n){
            //i can open NOice
            f(idx+1,open+1,close,s+'(',n,ans);
        }
        
        if(close<open){
            //wE have to close also bC nvm.
            f(idx+1,open,close+1,s+')',n,ans);
        }
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        //2*n is the base case hm.
        vector<string>ans;
        f(0,0,0,"",n,ans);
        return ans;
    }
};