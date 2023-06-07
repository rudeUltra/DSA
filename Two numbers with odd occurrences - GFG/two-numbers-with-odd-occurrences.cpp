//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long x;
        
        for(int i=0;i<N;++i){
            x=x^Arr[i];
        }
        
        //get the rightmost set bit siu to diffrentiate the 2 remaining numbers
        long long set_bit=x & ~(x-1);
        long long x1=0,y1=0;
        for(int i=0;i<N;++i){
            if(Arr[i] & set_bit){
                x1=x1^Arr[i];
            }
            else{
                y1=y1^Arr[i];
            }
        }
        vector<long long>ans;
        if(x1>y1){
            ans.push_back(x1);
            ans.push_back(y1);
        }
        else{
            ans.push_back(y1);
            ans.push_back(x1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends