class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
         

            
        for(int i=0;i<32;++i){
            //INT are 32 bits sized hm
            int start_bit=(start>>i)&1;
            int goal_bit=(goal>>i)&1;
            
            if(i<5){
                cout<<start_bit<<" "<<goal_bit<<" ";
            }
            if(start_bit ^ goal_bit){
                count++; //DIFFerent siu
            }
            
            //xOR MEANS different hm
        }
        
        return count;
    }
};