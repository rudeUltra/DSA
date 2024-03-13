class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        
        vector<int>curr=intervals[0];
        
        for(int i=1;i<n;++i){
            if(curr[1]>=intervals[i][0]){
                curr[0]=min(curr[0],intervals[i][0]);
                curr[1]=max(curr[1],intervals[i][1]);
                //Noice
            }
            else{
                //Hm OK.
                ans.push_back(curr);
                curr=intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};