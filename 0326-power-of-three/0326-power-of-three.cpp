class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1){
            return true;
        }
        if(n<3){
            return false;
        }
        int a=3;
        
        double p=log10(n)/log10(a);
        if(p-(int)p==0){
            return true;
        }
        
        return false;;
    }
};