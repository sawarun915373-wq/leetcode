class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<long long, long long> bucket;
        long long w = (long long)valueDiff + 1;
        auto getId = [&](long long x) {
            return x >= 0 ? x / w : (x + 1) / w - 1;
        };
        for (int i = 0; i < (int)nums.size(); i++) {
            long long x = nums[i];
            long long id = getId(x);
            if (bucket.count(id)) return true;
            if (bucket.count(id - 1) && llabs(x - bucket[id - 1]) <= valueDiff) return true;
            if (bucket.count(id + 1) && llabs(x - bucket[id + 1]) <= valueDiff) return true;
            bucket[id] = x;
            if (i >= indexDiff) bucket.erase(getId(nums[i - indexDiff]));
        }
        return false;
    }
};