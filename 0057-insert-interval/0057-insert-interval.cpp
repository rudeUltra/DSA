class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();

      
         vector<vector<int>>ans;

        
       
        for(int i=0;i<n;++i){
            if(intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newInterval[1]){
                
                ans.push_back(newInterval);
                for(int j=i;j<n;++j){
                    ans.push_back(intervals[j]);
                    //push all since sorted
                }
                return ans;
            }
            else{
                //overlap
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            
            }
        }
       ans.push_back(newInterval);
        
        return ans;
    }
};