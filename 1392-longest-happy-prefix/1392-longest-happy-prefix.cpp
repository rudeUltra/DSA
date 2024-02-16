class Solution {
public:
    string longestPrefix(string s) {
        //bruh this is just KMP..SIUUU
        int n=s.size();
        //think logically for the code of KMp siu
        vector<int>kmp(n,0); //AyyO
        int right=1;
        int prev=0;
        
        while(right<n){
            if(s[right]==s[prev]){
                //noIce
                kmp[right]=prev+1;
                prev++;
                right++; //Nice metch metch
            }
            else{
                //no metch so Sed
                if(prev!=0){
                    prev=kmp[prev-1]; //try to match smaller substring hm.
                }
                else{
                    //NO hOpe move on BhAI MOye moye
                    kmp[right]=0;
                    right++;
                }
            }
        }
        
        

        

        
        //KMP[n-1] because that is the largest suffix which is also a prefix

        //we cannot pick substring in between which are also prefix/suffix because in this question it 
        //is required to find the suffix of the entire string not subparts check examples to understand siu

        string ans=s.substr(0,kmp[n-1]); //0+x not 0 to range SIU


        return ans;
    }
};