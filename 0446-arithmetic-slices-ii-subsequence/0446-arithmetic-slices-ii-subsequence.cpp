class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //hmm doable noice
        int n=nums.size();
        
        map<pair<int,long long>,int>mp;
        
        //Lis pattern hm
        
        int ans=0;
        
        for(int i=1;i<n;++i){
            
            for(int j=0;j<i;++j){
                long long diff=((1LL)*nums[i]-(1LL)*nums[j]);
                
                if(mp[{j,diff}]!=0){
                    
                    if(i>1){
                        ans=ans+mp[{j,diff}];
                    } //more than 3 hm
                }
                
                mp[{i,diff}]=mp[{i,diff}]+mp[{j,diff}]+1;
            }
            
        }
        
        return ans;
    }
};