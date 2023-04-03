class Solution {
public:
   int solve(string &s,int ind,vector<int> &dp){
		if(ind == s.size()) return 0;

		if(dp[ind] != -1) return dp[ind];

		int ans=INT_MAX;
		for(int i=ind;i<s.size();i++){
			if(isPalindrome(s,ind,i)){
				int temp=1+solve(s,i+1,dp);
				ans = min(ans,temp);
			}
		}
		return dp[ind]=ans;
	}

	bool isPalindrome(string &s,int start,int end){
		while(start <= end){if(s[start++] != s[end--]) return false;}
		return true;
	}
	int minCut(string s) {
		int n = size(s);
		if(n==1) return 0;
		vector<int>dp(n,-1);
		return solve(s,0,dp)-1;
	}
};