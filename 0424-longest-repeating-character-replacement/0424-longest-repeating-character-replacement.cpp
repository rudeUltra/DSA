class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        
        int left=0;
        int right=0;
        unordered_map<char,int>mp;
        while(right<n){
            mp[s[right]]++; //nOice
            
            int mx=0; //Get the max freq HM.
            //only 26 letters so gg Ez
            for(auto it:mp){
                mx=max(mx,it.second);
            }
            
            //Invalid case hm.
            while((right-left+1)-mx>k){
                //noPe
                mp[s[left]]--;
                left++;
            }
            
            //valid length Hm.
            ans=max(ans,(right-left+1));
            right++;
        }
        
        return ans;
    }
};