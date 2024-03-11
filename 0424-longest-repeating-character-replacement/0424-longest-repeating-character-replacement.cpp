class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>hash(26,0);
        
        int left=0;
        int right=0;
        
        int ans=0;
        
        while(right<n){
            hash[s[right]-'A']++;
            
            //Check invalid case hm.
            int mx=0;
            for(int i=0;i<26;++i){
                mx=max(mx,hash[i]);
            }
            
            if((right-left+1)-mx>k){
                hash[s[left]-'A']--;
                left++;
            }
            ans=max(ans,(right-left+1));
            right++;
        }
        return ans;
    }
};