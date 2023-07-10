class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(n==1)return x;
        if(n>0){
        if(n%2==0)return myPow(x*x,n/2);
        else return x*myPow(x*x,n/2);
        }
        else{
            n=abs(n);
            if(n%2==0)return 1/(myPow(x*x,n/2));
        else return 1/(x*myPow(x*x,n/2));
       
        }
        
    }
};