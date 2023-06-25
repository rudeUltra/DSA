class Solution {
public:
    void performOperations(vector<int> &h,stack<int> &st,int i) {
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            if(h[top] > h[i]) {
                h[top] -= 1;
                h[i] = 0;
                st.push(top);
                return ;
            } else if(h[top] == h[i]) {
                h[i] = 0, h[top] = 0;
                return ;
            }
            else {
                h[i] -= 1;
                h[top] = 0;
            }
        }
    }
    vector<int> survivedRobotsHealths(vector<int>& v, vector<int>& h, string s) {
        stack<int> st;
        int n = v.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i += 1) idx[i] = i;
        sort(idx.begin(),idx.end(),[&](int i, int j) {
           return v[i] < v[j]; 
        });
        for(int j = 0; j < n; j += 1) {
            int i = idx[j];
            if(s[i] == 'L' && st.empty()) continue;
            else if(s[i] == 'R') st.push(i);
            else {
                performOperations(h, st, i);
            }
        }
        vector<int> ans;
        for(int x : h) {
            if(x) ans.push_back(x);
        }
        return ans;
    }
};