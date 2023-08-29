class Solution{
    public:
    void dfs(string &num, int start, int target, string path, long prev, long cur, vector<string> &res) {
	if(start == num.size() && prev + cur == target) res.push_back(path);

	for(int i = 1; start + i <= num.size(); i++) {
		string s = num.substr(start, i);
		long n = stoll(s);
		if(to_string(n).size() != s.size()) return;
		if(!start) dfs(num, i, target, s, 0, n, res);
		else {
			dfs(num, start + i, target, path + "+" + s, prev + cur, n, res);
			dfs(num, start + i, target, path + "-" + s, prev + cur, -n, res);
			dfs(num, start + i, target, path + "*" + s, prev, cur * n, res);
		}
	}
}

vector<string> addOperators(string num, int target) {
	vector<string> res;
	dfs(num, 0, target, "", 0, 0, res);
	return res;
}

    
};



