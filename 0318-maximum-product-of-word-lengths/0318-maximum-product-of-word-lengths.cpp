class Solution {
public:
    
    bool isValid(vector<int>&a,vector<int>&b){
        for(int i=0;i<26;++i){
            if(a[i]!=0 && b[i]!=0){
                return false;
            }
        }
        
        return true;
    }
    int maxProduct(vector<string>& words) {
        //hASh each Word's vector Noice
        
        int n=words.size();
        
        vector<pair<int,vector<int>>>dp;
        for(int i=0;i<n;++i){
            vector<int>freq(26,0);
            string curr=words[i];
            
            for(int j=0;j<curr.size();++j){
                freq[curr[j]-'a']++;
            }
            dp.push_back({curr.size(),freq});
            //length we will get from index hm.
        }
        
        int ans=0;
        
        for(int i=0;i<n-1;++i){
            int currSize=words[i].size();
            
            for(int j=i+1;j<n;++j){
                vector<int>curr=dp[j].second;
                int wordSize=dp[j].first;
                if(isValid(curr,dp[i].second)){
                    ans=max(ans,(currSize*wordSize));
                }
            }
        }
        //N^2.26
        
        return ans; //mIght Work INshallah
    }
};