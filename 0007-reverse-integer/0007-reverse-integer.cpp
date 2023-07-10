class Solution {
public:
    int reverse(int x) {
        int c=0;
        while(x!=0){
            if(c>(INT_MAX/10 )|| c<(INT_MIN/10))
                return 0;
            c= c*10 + x%10;
            x= x/10;
        }
        return c;
    }
};