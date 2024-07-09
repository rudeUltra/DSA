class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double ans=0;
        
        int current=0;
        
        for(int i=0;i<n;++i){
            if(customers[i][0]<current){
                //has to wait hm.
                ans=ans+(current-customers[i][0])+customers[i][1];
                current=current+customers[i][1];
            }
            else{
                ans+=(customers[i][1]+customers[i][0])-customers[i][0];
                current=customers[i][0]+customers[i][1];
            }
            
            
            
        }
        return ans/n;
    }
};