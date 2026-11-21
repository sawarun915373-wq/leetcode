class Solution {
    bool check(TreeNode* node, const long long* lo, const long long* hi) {
        if (!node) return true;
        long long v = node->val;
        if (lo && v <= *lo) return false;
        if (hi && v >= *hi) return false;
        return check(node->left, lo, &v) && check(node->right, &v, hi);
    }

public:
    bool isValidBST(TreeNode* root) {
        return check(root, nullptr, nullptr);
    }
};