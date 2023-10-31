class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int prev=0;
        int n=pref.size();
        
        vector<int>ans(n);
        
        ans[0]=pref[0];
        
        prev=pref[0];
        
        for(int i=1;i<n;++i){
            int curr=pref[i];
            int req=curr^prev;
            ans[i]=req;
            prev=prev^req;
        }
        
        return ans;
    }
};