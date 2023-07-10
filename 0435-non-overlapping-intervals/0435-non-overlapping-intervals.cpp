class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int prevEnd =intervals[0][1];
        
        for(int i=1;i<n;++i){
            int start=intervals[i][0];
            int end=intervals[i][1];
            
            if(prevEnd > start){
                //overlapping interval bruh
                prevEnd = min(prevEnd,end);
                count++;
            }
            else{
                prevEnd=end;
            }
        }
        return count;
    }
};