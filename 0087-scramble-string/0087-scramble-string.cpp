class Solution {
    bool dfs(string s, string t, unordered_map<string, bool> &dp) {
        if(s == t) return true;
        if(dp.find(s + " " + t) != dp.end()) return dp[s + " " + t];

        int n = s.size();
        for(int k=1; k<n; k++) {
            bool notswap = dfs(s.substr(0, k), t.substr(0, k), dp) && dfs(s.substr(k), t.substr(k), dp);
            bool swap = dfs(s.substr(0, k), t.substr(n - k), dp) && dfs(s.substr(k), t.substr(0, n - k), dp);
            if(swap || notswap) return dp[s + " " + t] = true;
        }
        return dp[s + " " + t] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> dp;
        return dfs(s1, s2, dp);
    }
};