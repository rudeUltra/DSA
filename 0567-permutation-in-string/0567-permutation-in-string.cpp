class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>m1(26,0);
        vector<int>m2(26,0);
        int n=s1.length();
        int m=s2.length();
        int right=0;
        if(n>m){
            return false;
        }
        while(right<n){
            m1[s1[right]-'a']++;
            m2[s2[right]-'a']++;
            right++;
        }
        right--;
        int left=0;
        while(right<m){
            if(m1==m2){
                return true; // comparing vectors so no need to iterate over a map nice
            }
            right++;
            if(right!=m){
                m2[s2[right]-'a']++;
            }
            m2[s2[left]-'a']--;
            left++;
        }
        return false;
    }
};