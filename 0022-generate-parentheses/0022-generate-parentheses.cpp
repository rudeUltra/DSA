class Solution {
public:
    vector<string>ans;
    vector<string> generateParenthesis(int n) {
        string temp;
        f(0,0,n,temp);
        return ans;
    }
    void f(int start,int close,int n,string curr){
        if(curr.size()==n*2){
            //max no of brackets will be n*2
            ans.push_back(curr);
            return;
        }
        
        if(start<n){
            //we can add opening tags so
            f(start+1,close,n,curr+'(');
        }
        if(close<start){
            //have to balance the brackets
            
            f(start,close+1,n,curr+')');
        }
    }
};