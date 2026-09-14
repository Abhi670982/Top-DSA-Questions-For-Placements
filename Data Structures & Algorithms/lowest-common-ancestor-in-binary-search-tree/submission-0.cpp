class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;

        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);

        if(left && right)
            return root;

        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};