class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int>mp;
        int n=answerKey.size();
        
        int left=0;
        int right=0;
        int ans=1;
        while(right<n){
            mp[answerKey[right]]++;
            
            
            int mx=0;
            for(auto it:mp){
                mx=max(mx,it.second);
            }
            //dont store it in temp just use left and right pointers siu
            
            while((right-left+1)-mx>k){
                
                mp[answerKey[left]]--;
                left++;
            }
            ans=max(ans,(right-left+1));
            right++;
        }
        return ans;
    }
};