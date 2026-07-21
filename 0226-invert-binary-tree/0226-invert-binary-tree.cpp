class Solution {
public:
    void solve(TreeNode* root){
        if(!root) return;
        swap(root->left, root->right);
        solve(root->left);
        solve(root->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};