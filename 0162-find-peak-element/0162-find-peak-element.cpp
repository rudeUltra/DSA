class Solution {
public:
    int findPeakElement(vector<int>& nums) {
          int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1; //since it is guaranteed that we have a peak
            
            //there are alternating ascending and descending slopes!
            
            //if we are on a descending slope obvs peak will be behind r=mid-1
            
            // if we are on an ascending slope peak obbse will be ahead of us siu so l=mid+1;
        }
        return l;
    }
};