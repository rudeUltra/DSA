class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        int n=s.size();
        if(n==0){
            return true;
        }
        for(int i=0;i<n;++i){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                if(isupper(s[i])){
                    s[i]=s[i]+32; //upper to lowe ASCII
                }
                temp.push_back(s[i]);
            }
        }
        int i=0;
        int j=temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};