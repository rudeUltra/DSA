class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>prev(n);
        vector<int>next(n);

        for(int i=0;i<n;++i){
            prev[i]=i;
            next[i]=n-i-1;
        }

        stack<int>st1,st2;
        //st1 for prev for prev just do reverse big brain xD

        //st2 for next

        for(int i=0;i<n;++i){
            while(!st2.empty() && arr[st2.top()]>=arr[i]){
                next[st2.top()]=i-st2.top()-1;
                st2.pop(); //store indexes not elements
            }

            st2.push(i);
        }

        
        for(int i=n-1;i>=0;--i){
            while(!st1.empty() && arr[st1.top()]>arr[i]){
                prev[st1.top()]=st1.top()-i-1;
                st1.pop(); //store indexes not elements
            }

            st1.push(i);
        }

        long long ans=0;
        int mod=1e9+7;
        
        for(int i=0;i<n;++i){
            cout<<next[i]<<" ";
        }
        cout<<endl;
        
        for(int i=0;i<n;++i){
            cout<<prev[i]<<" ";
        }
        for(int i=0;i<n;++i){
            ans=ans+((prev[i]+1)*(1LL)*(next[i]+1)*arr[i]); //multiply by arr[i] bcus we want sum siu
            //This is combinations OMG big brain
            ans=ans%mod;
        }

        return ans%mod;



    }
};