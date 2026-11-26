class Solution {
    int check(TreeNode* node) {
        if (!node) return 0;

        int l = check(node->left);
        if (l == -1) return -1;

        int r = check(node->right);
        if (r == -1) return -1;

        if (abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};