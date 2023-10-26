class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        //very Intuituive question mate hm
        int n=arr.size();
        
        unordered_map<int,long>mp;
        
        
        sort(arr.begin(),arr.end());
        mp[arr[0]]=1;
        //build the ans frrom smol to big
        //Initially everyone will have 1 but ok
        
        for(int i=1;i<n;++i){
            long count=1; //intitial
            
            for(auto it:mp){
                //We can use multiple times siu
                if(arr[i]%it.first==0 && mp.find(arr[i]/it.first)!=mp.end()){
                    count+=mp[it.first]*mp[arr[i]/it.first]; //No of ways siu
                }
            }
            mp[arr[i]]=count; //for this rooot this is the no of trees possible
        }
        
        int ans=0;
        const int mod=1e9+7;
        
        for(auto it:mp){
            ans=((ans%mod)+(it.second%mod))%mod;
        }
        
        return ans;
    }
};