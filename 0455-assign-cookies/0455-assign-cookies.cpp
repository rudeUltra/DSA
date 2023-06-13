class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int n=g.size();
        int m=s.size();
        int i=0;
        int j=0;
        int count=0;
        while(i<n && j<m){
            //two pointer less goo
            if(g[i]<=s[j]){
                ++i;
                ++j; //cookie assigned
                count++;
            }
            else{
                ++j;
            }
        }
        return count;
    }
};