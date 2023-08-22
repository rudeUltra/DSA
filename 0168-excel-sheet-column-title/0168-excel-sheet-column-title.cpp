class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
        while(columnNumber){
            columnNumber--; //Minus 1 because we start from 0 not 1
            int a=columnNumber%26;
            s+=('A'+a);
            columnNumber/=26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};