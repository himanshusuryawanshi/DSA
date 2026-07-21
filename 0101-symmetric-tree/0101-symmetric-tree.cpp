/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* Left, TreeNode* Right){
        if(!Left and !Right) return true;
        if(!Left or !Right) return false;
        if(Left->val != Right->val) return false;

        return solve(Left->left, Right->right) and solve(Left->right, Right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return solve(root->left,root->right);
    }
};