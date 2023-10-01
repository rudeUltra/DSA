class Solution {
public:
    string reverseWords(string s) {
        int left=0;
        int n=s.length();
        for(int i=0;i<n;++i){
            if(isspace(s[i]) || i==n-1){
                int j=0;
                if(i==n-1){
                    j=i;
                }
                else{
                    j=i-1;
                }
                while(left<j){
                    int temp=s[left];
                    s[left]=s[j];
                    s[j]=temp;
                    ++left;
                    --j;
                }
                left=i+1;
            }
        }
        return s;
        
    }
};