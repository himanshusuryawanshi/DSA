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
    void solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans){
        if(root==NULL) return;
        // if(root==p or root==q){
        //     ans = root; return;
        // }

        if((root->val < p->val) && (root->val < q->val)){
            return solve(root->right, p,q,ans);
        }else if((root->val > p->val) && (root->val > q->val)){
            return solve(root->left,p,q,ans);
        }else{
            ans = root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        solve(root,p,q,ans);
        return ans;
    }
};