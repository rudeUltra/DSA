class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total=numBottles;
        
        while(numBottles){
            int temp=0;
            if(numBottles>numExchange){
                temp=(numBottles)%numExchange;
            }
            numBottles=(numBottles)/numExchange;
            total+=numBottles;
            numBottles+=temp;
            cout<<numBottles<<" ";
        }
        
        return total;
    }
};