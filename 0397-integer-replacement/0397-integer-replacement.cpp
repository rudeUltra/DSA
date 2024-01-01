class Solution {
public:
    int integerReplacement(long n) {
        int count = 0;
        while(n != 1) {
            if(n % 2 == 0) {
                n /= 2;
            } else if(n == 3 || (n & 3) == 1) {
                n -= 1;
            } else if((n & 3) == 3) {
                n += 1;
            }

            count++;
        }
        return count;
    }
};