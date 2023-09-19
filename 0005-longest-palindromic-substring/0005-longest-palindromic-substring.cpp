//bottom-up approach
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0; // Starting index of the longest palindromic substring
        int longlen = 1; // Length of the longest palindromic substring (initialize to 1, as each character is a palindrome by itself)
        
        // Create a table to store the results of subproblems
        vector<vector<bool>> t(n, vector<bool>(n, false));
        
        // All substrings of length 1 are palindromic
        for (int i = 0; i < n; i++)
            t[i][i] = true;
        
        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) 
        {
            if (s[i] == s[i + 1])
            {
                t[i][i+1] = true;
                start = i;
                longlen = 2;
            }
        }
        
        // Check for substrings of length 3 or more
        for (int l = 3; l <= n; l++) 
        {
            for (int i = 0; i < n - l + 1; i++) 
            {
                int j = i + l - 1; // Ending index of the current substring
                // Check if the substring from i to j is a palindrome
                if (s[i] == s[j] && t[i + 1][j - 1]) 
                {
                    t[i][j] = true;
                    if (l > longlen) 
                    {
                        longlen = l;
                        start = i;
                    }
                }
            }
        }
        
        //Extract the longest palindromic substring from original string
        return s.substr(start, longlen);
    }
};