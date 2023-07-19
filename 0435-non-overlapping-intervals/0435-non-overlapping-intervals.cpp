class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //greedy min of the ends siu if intersecting/overlapping
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int prev=intervals[0][1];
        int start=intervals[0][0];
        int count=0;
        for(int i=1;i<n;++i){
            if(prev>intervals[i][0]){
                count++;
                prev=min(prev,intervals[i][1]);
            }
            else{
                prev=intervals[i][1];
            }
        }
        
        return count;
    }
};