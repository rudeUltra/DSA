class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> common;
        for (int x: s1) {
            if (s2.find(x) != s2.end()) {
                common.insert(x);
            }
        }
        int n = nums1.size(), n1 = s1.size(), n2 = s2.size(), c = common.size();
        return min(n, min(n1 - c, n / 2) + min(n2 - c, n / 2) + c);
    }
};