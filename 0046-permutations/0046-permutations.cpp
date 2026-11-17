class Solution {
    void dfs(vector<int>& nums, int start, vector<vector<int>>& res) {
        int n = nums.size();
        if (start == n) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < n; i++) {
            swap(nums[start], nums[i]);
            dfs(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }
};