class Solution {
public:
    
    
    
    vector<int> Zfunction(string &ans){
        //O(N) time complexity noice
        int n=ans.size();
        vector<int>z(n,0);
        z[0]=0; //sED
        int left=0;
        int right=0;
        
        for(int k=1;k<n;++k){
            if(k>right){
                //sED
                left=right=k;
                
                while(right<n && ans[right-left]==ans[right]){
                    right++;
                }
                
                z[k]=right-left;
                right--;
            }
            else{
                //try to get the answer from the window Hm.
                int k1=k-left;
                if(z[k1]+k<=right){
                    //Reuse the values hm.
                    z[k]=z[k1];
                }
                else{
                    left=k;
                    while(right<n && ans[right-left]==ans[right]){
                        right++;
                    }
                    z[k]=right-left;
                    right--;
                }
            }
        }
        
        return z;
        
        
    }
    
    
    
    int strStr(string haystack, string needle) {
        //let's solve it using Z-function noice
        
        //Z-function is based on creating a Z array so that longest substring at index k which is also a prefix of the entire array Hm noice
        
        string ans=needle+'$'+haystack;
        
        vector<int>z=Zfunction(ans);
        
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<(n+m+1);++i){
            cout<<z[i]<<" ";
            if(z[i]==m){
                return i-(m+1); //gOteMM
            }
        }
        
        
        return -1;
    }
};