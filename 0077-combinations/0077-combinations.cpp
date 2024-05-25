class Solution {
public:
    
    
    void f(int idx,int n,int k,vector<int>&temp,vector<vector<int>>&ans){
        
        if(temp.size()==k){
            //COrrect combination Add It Hm.
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<=n;++i){
            cout<<"Index"<<idx<<" "<<i<<" ";
            temp.push_back(i);
            f(i+1,n,k,temp,ans);
            temp.pop_back(); //Backtrack hm.
        }
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        //niCE sum
        vector<vector<int>>ans;
        vector<int>temp; //for backtracking NoICE.
        
        f(1,n,k,temp,ans);
        
        return ans;
    }
};