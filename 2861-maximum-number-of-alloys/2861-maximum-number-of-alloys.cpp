#define ll long long

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        ll res = 0;
        for (int i = 0; i < k; i++)
        {
            ll low = 0, high = 1e9;
            while(low <= high) {
                ll mid = (low + high) / 2, cur = 0;
                for (int j = 0; j < n; j++)
                {
                    ll need = mid * composition[i][j];
                    need = max(0LL, need - stock[j]);
                    cur += cost[j] * need;
                }
                if(cur <= budget) {
                    res = max(res, mid);
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return res;
    }
};