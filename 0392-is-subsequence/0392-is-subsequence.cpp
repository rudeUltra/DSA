class Solution {
public:
    bool isSubsequence(string s, string t) {
        //Two pointers boii
        int n=s.size();
        int m=t.size();
        
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                ++i;
                ++j;
            }
            else{
                ++j;
            }
        }
        if(i==n){
            //all metched siu
            return true;
        }
        return false;
    }
};