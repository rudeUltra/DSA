class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        
        for(int i=31;i>=0;--i){
            int start_bit=(start>>i)&1;
            int goal_bit=(goal>>i)&1;
            
            if(start_bit!=goal_bit){
                count++;
            }
            
        }
        return count;
    }
};