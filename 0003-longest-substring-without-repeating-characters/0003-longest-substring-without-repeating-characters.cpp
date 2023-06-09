class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=INT_MIN;
        int n=s.length();
        int left=0;
        int right=0;
        unordered_map<char,int>mp;
        
        if(n==0){
            return 0;
        }
        while(right<n){
            
            cout<<mp[right]<<" ";
            
            if(mp[s[right]]==0){
                //unique character siu
                ans=max(ans,(right-left+1));
                mp[s[right]]++;
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