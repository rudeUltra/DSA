class Solution {
public:
    void backtrack(string s, int i, int dots, string currIp, vector<string>& res) {
        if (dots == 4 && i == s.length()) {
            res.push_back(currIp.substr(0, currIp.length() - 1));
            return;
        }
        if (dots > 4) 
            return;

        for (int j = i; j < min(i+3, (int)s.length()); j++) {
            //the i==j check is used to determine if the current substring being considered as a part of the IP address is a single digit or not. If i is equal to j, it means that the current substring is a single digit. This check is used in conjunction with the check s[i] != '0' to ensure that the IP address being considered is a valid one, where each segment is between 0-255 and no leading zeroes are present.
            if (stoi(s.substr(i, j-i+1)) < 256 && (i == j || s[i] != '0')) {
                backtrack(s, j+1, dots+1, currIp + s.substr(i, j-i+1) + ".", res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() > 12)
            return res;
        backtrack(s, 0, 0, "", res);
        return res;
    }
};
