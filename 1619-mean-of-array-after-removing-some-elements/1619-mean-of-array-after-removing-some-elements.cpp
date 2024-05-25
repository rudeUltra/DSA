class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int p = (5 * n) / 100;
        double ans = 0;
        for(int i=p;i<n-p;i++) ans += arr[i];
        ans /= (n - (p*2));
        return ans;
    }
};