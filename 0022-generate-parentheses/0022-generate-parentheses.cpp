class Solution {
public:
    void f(int idx,int n,int open,int close,string temp,vector<string>&ans){
        if(idx==2*n){
            ans.push_back(temp);
            return;
        }
        if(open<n){
            //hm
            f(idx+1,n,open+1,close,temp+'(',ans);
        }
        
        if(close<open){
            f(idx+1,n,open,close+1,temp+')',ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        //2 interesting observation edge case + decision
        string temp;
        vector<string>ans;
        
        f(0,n,0,0,temp,ans);
        
        return ans;
    }
    
    
};