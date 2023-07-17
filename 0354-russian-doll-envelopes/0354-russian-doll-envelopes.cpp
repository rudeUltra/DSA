class Solution {
public:
   static bool cmp(vector<int>& a, vector<int>& b)
{
    if(a[0]==b[0]) return a[1] > b[1];
    return a[0] < b[0];
}
 int solveOptimal(vector<vector<int>>& arr) {
        if(arr.size() == 0)
            return 0;
        vector<int> ans;
        ans.push_back(arr[0][1]);

        for(int i=1; i<arr.size(); i++) {
            if(arr[i][1]> ans.back()) {
                //include
                ans.push_back(arr[i][1]);
            }
            else {
                //overwrite
                //find index of just bada element
                int index = lower_bound(ans.begin(), ans.end(), arr[i][1]) - ans.begin();
                ans[index] = arr[i][1];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
       
        sort(envelopes.begin(), envelopes.end(),cmp);

        //apply lis logic
        int ans = solveOptimal(envelopes);
        return ans;
    }
};