class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I']=1;
                m['V']=5;
                m['X']=10;
                m['L']=50;
                m['C']=100;
                m['D']=500;
                m['M']=1000;
        int n=s.size();
        int i=0;
        int ans=0;
       while(i<n){
           if(i<n-1 && m[s[i+1]]>m[s[i]]){
               //bruh
               ans=ans+m[s[i+1]]-m[s[i]];
               i=i+2;
               continue;
           }
           else{
               ans=ans+m[s[i]];
           }
           ++i;
       }
        
       
        return ans;
        
    }
};