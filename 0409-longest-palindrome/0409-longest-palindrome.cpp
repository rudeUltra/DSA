class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        int count=0;
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<n;++i){
            mp[s[i]]++;
        }
        int odd=0;
        //Iterate through the map hm
        for(auto it:mp){
            if(it.second%2==0){
                count+=it.second;
            }
            else{
                count=count+(it.second-1);
                if(odd==0){
                    count++;
                    odd=1;
                }
            }
        }
        
        return count;
    }
};