/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans){
        if(root==NULL) return 0;
        int left = solve(root->left,p,q,ans);
        int right = solve(root->right,p,q,ans);
        int total = left + right + (root==p or root==q);
        if(total == 2 and ans==NULL) ans = root;
        return total; 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        solve(root,p,q,ans);
        return ans;
    }
};