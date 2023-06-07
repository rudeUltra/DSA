class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        
        for(int i=0;i<32;++i){
            
            cout<<(goal&1)<<" ";
            
            if((start&1)!=(goal&1)){
                count++;
            }
            
            start=start>>1;
            goal=goal>>1;
            
        }
        
        return count;
    }
};