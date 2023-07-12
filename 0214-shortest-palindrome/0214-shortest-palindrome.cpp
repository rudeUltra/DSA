class Solution {
public:
    string shortestPalindrome(string s) 
    {
        reverse(s.begin(), s.end());
        string rev = s;
        reverse(s.begin(), s.end());
        string temp = s + "@" + rev;
        vector<int> vr = fail_fun(temp);

        int maxm = vr[vr.size()-1];

        temp = "";
        for(int i = maxm; i < s.length(); i++)
        {
            temp = temp + s[i];
        }        
        reverse(temp.begin(), temp.end());
        return temp + s;
    }

    vector<int> fail_fun(string &s)
    {
        int n = s.length();
        vector<int> fail_ar(n, 0);

        for(int i = 1, k = 0; i < n; i++)
        {
            while(k > 0 && s[k] != s[i])
            {
                k = fail_ar[k-1];
            }

            if(s[k] == s[i])
            {
                fail_ar[i] = ++k;
            }
        }

        return fail_ar;
    }
};