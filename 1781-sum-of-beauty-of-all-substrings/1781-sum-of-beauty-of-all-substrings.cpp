class Solution {
public:
    int check(vector<int> &v){
        int mx = 0, mn = INT_MAX;
        for(int i = 0; i < 26; i++){
            mx  = max(v[i],mx);
            mn = min(mn,(v[i]==0?INT_MAX:v[i]));
        }
        if(mn == 0)return 0;
        return mx-mn;
    }
    int beautySum(string s) {
        vector<int> v(26,0);
        int i,j,n = s.length(),ans = 0;
        for(i = 0; i < n; i++){
            fill(v.begin(),v.end(),0);
            for(j = i; j < n; j++){
                v[s[j]-'a']++;
                ans += check(v);
            }
        }
        return ans;
    }
};