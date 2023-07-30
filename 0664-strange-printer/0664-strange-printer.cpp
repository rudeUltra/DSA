class Solution {
public:
    int dp[101][101];
    int solve(string &s, int i, int j){
        if(i > j)
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];

        int x = i;
        while(x + 1 <= j && s[x] == s[x + 1])  //find the end of the first same character in the substring , x is the end 
            x++;   //stores the ending index of this sequence.

        int ans = 1 + solve(s,x + 1, j);   // number of turns needed to print the rest of the substring after the first same character sequence

        for(int k = x + 1; k <= j; k++){
            if(s[k] == s[i]){
                ans = min(ans, solve(s,k,j) + solve(s,x + 1, k - 1));  //solve(s, k, j) to find the minimum number of turns needed to print the rest of the substring after this character, and solve(s, x + 1, k - 1) to find the minimum number of turns needed to print the part of the substring between the first same character sequence and the current character
            }
        }
        return dp[i][j] = ans;
    }
    
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size() - 1);
    }
};