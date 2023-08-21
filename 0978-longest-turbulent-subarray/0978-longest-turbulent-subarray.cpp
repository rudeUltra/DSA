class Solution{
    public:
    bool isValid(vector<int>&a,int k){
        return ((a[k]>a[k+1]&&a[k]>a[k-1])||(a[k]<a[k+1]&&a[k]<a[k-1]));
    }

int maxTurbulenceSize(vector<int>& a) {
       long int start=0;
       long int end =0;
        long int n=a.size();
       long  int mx=1;
       if(n<2){
           return n;
       }
        while(start+1<n){
            if(a[start]==a[start+1]){
                start++;
                continue;
            }
            end=start+1;
            while(end+1<n &&isValid(a,end)){
                end++;
            }
            mx=max(mx,end-start+1);
            start=end;

            
        }
        return mx;
        
    }
};
