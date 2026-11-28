class Solution {
    unordered_map<int, int> pos;
    int postIdx;

    TreeNode* build(vector<int>& postorder, int l, int r) {
        if (l > r) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];
        root->right = build(postorder, mid + 1, r);
        root->left = build(postorder, l, mid - 1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) pos[inorder[i]] = i;
        postIdx = n - 1;
        return build(postorder, 0, n - 1);
    }
};