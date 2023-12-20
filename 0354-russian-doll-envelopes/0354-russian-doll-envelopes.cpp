class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        
        return a[0]<b[0];
        
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        //So scared to fail that i stopped writing code damn.
        //fail a million times idc.
        //Knowledge is priceless 
          int n=envelopes.size();
        
        sort(envelopes.begin(),envelopes.end(),cmp);
        
       
        
        vector<int>lis(n);
        for(int i=0;i<n;++i){
            lis[i]=(envelopes[i][1]);
        }
        
        
        vector<int>ans;
        
        ans.push_back(lis[0]);
        
        for(int i=1;i<n;++i){
           
            if(lis[i]>ans.back()){
                ans.push_back(lis[i]);
            }
            else{
                int idx=lower_bound(ans.begin(),ans.end(),lis[i])-ans.begin();
                ans[idx]=lis[i];
            }
        }
        
        return ans.size();
        
    }
};