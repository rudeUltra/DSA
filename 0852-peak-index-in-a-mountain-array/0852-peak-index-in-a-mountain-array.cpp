class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //potential ans type
        int ans=-1;
        int n=arr.size();
        
        int low=0;
        int high=n-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(mid>0 && arr[mid-1]<arr[mid] && mid<n && arr[mid+1]<arr[mid]){
                return mid;
            }
            else if(mid>0 && arr[mid-1]>arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans==-1?low:ans;
    }
};