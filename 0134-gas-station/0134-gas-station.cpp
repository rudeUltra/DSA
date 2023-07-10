class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum1=0;
        int sum2=0;
        int n=gas.size();
        for(int i=0;i<n;++i){
            sum1=sum1+gas[i];
            sum2=sum2+cost[i];
        }
        if(sum1<sum2){
            return -1; //not enough gas sad
        }
        int ans=0; //as lowest index as check diff array xD
        int sum=0;
        for(int i=0;i<n;++i){
            sum=sum+(gas[i]-cost[i]);
        
            if(sum<0){
                //no more contributing so we need a better ans!
                ans=i+1; //assume next index is the ans
                sum=0;
            }
        }
        return ans;
    }
};