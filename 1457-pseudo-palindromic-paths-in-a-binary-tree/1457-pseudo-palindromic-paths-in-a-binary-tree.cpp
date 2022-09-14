class Solution {
public:
    int ans = 0;
    
     unordered_map<int, int> mp;
   
    void helper(TreeNode* root){
        if(root==NULL) return ;
        
        mp[root->val]++;
        
        
       if(root->left==NULL && root->right==NULL)
     {
          int temp=0;
         for(int i=0; i<=9; i++)
          {
             if(mp[i]%2!=0) 
           temp++;
           }
         if(temp<=1) ans++; 
   }
    
    helper(root->left); 
    helper(root->right);
        
    mp[root->val]--;
       
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
       
        helper(root);
        return ans;
    }
};