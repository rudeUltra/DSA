class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>a(26,0);
        vector<int>b(26,0);
        
        for(int i=0;i<s.size();++i){
            a[s[i]-'a']++;
        }
        for(int i=0;i<t.size();++i){
            b[t[i]-'a']++;
        }
        for(int i=0;i<26;++i){
            if(a[i]!=b[i]){
                return 'a'+i;
            }
        }
        return 'a';
    }
};