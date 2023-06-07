//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	    vector<int>nextSmaller(n,-1);
	    stack<int>st;
	    for(int i=0;i<n;++i){
	        while(!st.empty() && arr[st.top()]>arr[i]){
	            //good ebening how could i help xD
	            nextSmaller[st.top()]=i;
	            st.pop();
	        }
	        st.push(i);
	    }
	    
	    for(int i=0;i<n;++i){
	        if(nextSmaller[i]==-1){
	            arr[i]=-1;
	        }
	        else{
	            if(nextSmaller[i]!=i+1){
	                arr[i]=-1;
	            }
	            else{
	                arr[i]=arr[i+1];
	            }
	        }
	    }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends