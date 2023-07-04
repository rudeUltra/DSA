class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n2<n1){
            return findMedianSortedArrays(nums2,nums1); //BIG brain way to swap
        }
        int low=0;
        int high=n1;
        
        while(low<=high){
            int cut1=(low+high)>>1; //divide by 2
            int cut2=(n1+n2+1)/2-cut1;
            
            int l1,l2,r1,r2;
            l1=cut1==0?INT_MIN:nums1[cut1-1];
            l2=cut2==0?INT_MIN:nums2[cut2-1];
            r1=cut1==n1?INT_MAX:nums1[cut1];
            r2=cut2==n2?INT_MAX:nums2[cut2]; //edge case 0.o
            
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0){
                    //even sus
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else{
                    return max(l1,l2);
                }
            }
            else if(l1>r2){
                high=cut1-1; //take fewer elements
            }
            else{
                low=cut1+1; //take more elements
            }
        }
        return 0.0;
    }
};