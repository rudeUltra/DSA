class Solution {
public:

	bool isOk(vector<int>&nums, int m, int x) { //checks if mid is a possible answer or not
		int n = nums.size();
		set<int> s; // set containing elements after i+x, sorted so that we can extract nearest element of nums[i] efficiently
		for (int i = n - x - 1; i >= 0; i--) {
			s.insert(nums[i + x]);
			// first insert [i + x]th element
			// we don't need to fill s again and again, we are using previously inserted values, so we are traversing from back
			auto it = s.lower_bound(nums[i]);
			if (it == s.begin()) {
				// if first element of set is greater than or equal to nums[i], so all other elements in set are going to have a larger difference so we check only for first element
				if (abs(*it - nums[i]) <= m) return true;
			} else {
				// if lower_bound is not at s.begin(), then we need to check previous point also
				// [5, 3, 2, 10, 15]
				// for i = 1, set = {2, 10, 15}
				// lower_bound(3) = 10
				// but there is 2 also in set having smaller absolute difference with 3 than 10
				// so we check for value smaller than lower_bound also
				if (abs(*it - nums[i]) <= m) return true;
				it--;
				if (abs(*it - nums[i]) <= m) return true;
			}
		}
		return false;
	}

	int minAbsoluteDifference(vector<int>& nums, int x) {
		int n = nums.size();
		int min_of_nums = *min_element(nums.begin(), nums.end());
		int max_of_nums = *max_element(nums.begin(), nums.end());
		int l = 0, r = max_of_nums - min_of_nums;
		// max value of answer can be the difference between max(nums) - min(nums);
		// min value of answer can be 0, if two numbers, which are x distance apart are equal
		// so our search space is from l = 0 to r = max_of_nums - min_of_nums
		// since search space is sorted 
		// we apply binary search on this range of answer which is sorted
		int res = -1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (isOk(nums, mid, x)) {
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return res;
	}
};