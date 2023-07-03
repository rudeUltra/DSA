class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m1;
        int n=s.size();
        int l=0;
        int r=0;
        int ans=INT_MIN;
        while(r<n){
            m1[s[r]]++;
            //COUNT mx
            int mx=INT_MIN;
            for(auto it:m1){
                mx=max(mx,it.second);
            }
            while((r-l+1)-mx>k){
                m1[s[l]]--;
                l++;
            }
            ans=max(ans,(r-l+1));
            ++r;
        }
        return ans;
    }
};