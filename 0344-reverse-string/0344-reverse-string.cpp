class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int n=s.size();
        int j=n-1;
        while(i<j){
            int temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            ++i;
            --j;
        }
    }
};