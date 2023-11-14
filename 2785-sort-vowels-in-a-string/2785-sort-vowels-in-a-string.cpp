class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U'){
            return true;
        }
        return false;
    }
    
    string sortVowels(string s) {
        string ans="";
        int n=s.size();
        vector<char>temp;
        int k=0;
        for(int i=0;i<n;++i){
            if(isVowel(s[i])){
                temp.push_back(s[i]);
            }
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;++i){
            if(!isVowel(s[i])){
                ans.push_back(s[i]);
            }
            else{
                ans.push_back(temp[k]);
                k++;
            }
        }
        return ans;
    }
};