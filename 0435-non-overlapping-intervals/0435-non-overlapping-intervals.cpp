class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        vector<int>curr=intervals[0];
        int n=intervals.size();
        
        for(int i=1;i<n;++i){
            if(curr[1]>intervals[i][0]){
                count++; //Kalesh
                curr[1]=min(curr[1],intervals[i][1]);
            }
            else{
                curr=intervals[i];
            }
        }
        return count;
    }
};