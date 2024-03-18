class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        int ans=1; //for last point it goes out of bound so 

        //If we have a conflict or merge leave it 

        //when we dont have a conflict meaning we have to update the prev and increment counter
        //see how far this merge goes how many balloons we can pop from 1 arrow lets see

        int prev=points[0][1];
        for(int i=1;i<n;++i){
            if(points[i][0]>prev){
                //no merge lul
                ans++;
                prev=points[i][1];
            }
            //keep finding the point for the arrow has to be minimum because has to reach both ballons
            //draw diagram if u can HM
            prev=min(prev,points[i][1]);
        }

        return ans;
    }
};