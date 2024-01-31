class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        //Fixed size hM nOice
        int n=arr.size();
        
        int ans=0;
        //U thot that he was special but he was just a sex bo 
        
        int left=0;
        int right=0;
        
        int sum=0;
        while(right<n && right<k){
            sum+=arr[right];
            right++;
        }
        right--;
        while(right<n){
            
            cout<<right<<" ";
            if(sum/k>=threshold){
                ans++;
            }
            right++;
            if(right<n){
                sum+=arr[right];
            }
            
            sum=sum-arr[left];
            left++;
            
            
        }
        
        return ans;
        
    }
};