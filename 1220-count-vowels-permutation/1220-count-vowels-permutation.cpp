class Solution {
public:
    
    int MOD=1e9+7;

    long long int f(int n, int i, char c, vector<vector<int>> &dp, unordered_map<char, int> &mp){
        
        if(i==n) return 1;
        
        long long count = 0;
        
        if(dp[mp[c]][i]!=-1) return dp[mp[c]][i]%MOD;
        
        if(c=='a'){
		// after a only e is allowed
            count += f(n, i+1, 'e', dp, mp);
        }
        
        if(c=='e'){
		// after e only a and i are allowed
            count += f(n, i+1, 'a', dp, mp);
            count += f(n, i+1, 'i', dp, mp);
        }
        if(c=='i'){
		// after i everthing except i is allowed
            count += f(n, i+1, 'a', dp, mp);
            count += f(n, i+1, 'e', dp, mp);
            count += f(n, i+1, 'o', dp, mp);
            count += f(n, i+1, 'u', dp, mp);
        }
        if(c=='o'){
		// after o only i and u are allowed
            count += f(n, i+1, 'i', dp, mp);
            count += f(n, i+1, 'u', dp, mp);
        }
        
        if(c=='u'){
		// after u only a is allowed
            count += f(n, i+1, 'a', dp, mp);
        }
        
        return dp[mp[c]][i] = count%MOD;
        
    }
    
    int countVowelPermutation(int n) {
        
		// map to convert char to int for using in dp vector for memoization purpose
        unordered_map<char, int> mp;
        mp['a'] = 0;
        mp['e'] = 1;
        mp['i'] = 2;
        mp['o'] = 3;
        mp['u'] = 4;
        
        vector<vector<int>> dp(5, vector<int>(n+1, -1));
		
				//call for each starting from each vowel after that for changing the character values our recursive call will take care of

        long long cnt = f(n, 1, 'a', dp, mp) + f(n, 1, 'e', dp, mp) + f(n, 1, 'i', dp, mp) + f(n, 1, 'o', dp, mp) + f(n, 1, 'u', dp, mp); 
        
        return cnt%MOD;
        
    }
};