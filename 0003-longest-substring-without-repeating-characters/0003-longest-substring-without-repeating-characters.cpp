class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //we can do if else here bcuz we can check the condition of valid directly SIU
        int n=s.size();
        int left=0;
        int right=0;
        int ans=0;
        unordered_map<int,int>mp;
        while(right<n){
            if(mp[s[right]]==0){
                mp[s[right]]++;
                ans=max(ans,(right-left)+1);
                right++;
            }
            else{
                mp[s[left]]--;
                left++;
            }
        }
        
        return ans;
        
    }
};