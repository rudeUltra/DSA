class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        int k=0;
        vector<int> a;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                a.push_back(nums1[i]);
                ++i;
                ++k;
            }
            else{
                a.push_back(nums2[j]);
                ++k;
                ++j;
            }
        }
        while(i<m){
            a.push_back(nums1[i]);
            ++i;
            ++k;
        }
        while(j<n){
            a.push_back(nums2[j]);
            ++j;
            ++k;
        }
        for(int i=0;i<k;++i){
            nums1[i]=a[i];
        }
    }
};