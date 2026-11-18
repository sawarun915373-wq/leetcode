class Solution {
    int lowerBound(vector<int>& nums, long long x) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < x) l = mid + 1;
            else r = mid;
        }
        return l;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        if (first == (int)nums.size() || nums[first] != target) return {-1, -1};

        int last = lowerBound(nums, (long long)target + 1) - 1;
        return {first, last};
    }
};