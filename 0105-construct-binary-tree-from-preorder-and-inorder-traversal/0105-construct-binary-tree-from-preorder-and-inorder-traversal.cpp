class Solution {
    unordered_map<int, int> pos;
    int preIdx;

    TreeNode* build(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];
        root->left = build(preorder, l, mid - 1);
        root->right = build(preorder, mid + 1, r);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) pos[inorder[i]] = i;
        preIdx = 0;
        return build(preorder, 0, n - 1);
    }
};