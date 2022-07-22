class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        map<int, map<int, multiset<int> > > value;
        
        queue< pair<TreeNode*, pair<int,int> > > q;
        q.push( {root, {0,0}} );
        
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            TreeNode* frontnode = front.first;
            int vertical = front.second.first;
            int level = front.second.second;
            
            value[vertical][level].insert(frontnode->val);
            
            if(frontnode->left)
            {
                q.push({frontnode->left, {vertical-1, level+1}});
            }
            if(frontnode->right)
            {
                q.push({frontnode->right, {vertical+1, level+1}});
            }
        }
        
        
        for(auto p: value)
        {
            vector<int> level;
            for(auto q: p.second)
            {
                level.insert(level.end(), q.second.begin(),q.second.end());
            }
            ans.push_back(level);
        }
        return ans;
    }
};
