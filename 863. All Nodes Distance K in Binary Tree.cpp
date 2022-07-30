class Solution {
private:
    void mark_parent(TreeNode* root,  unordered_map<TreeNode*, TreeNode*>& parent_track)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();
            if(current->left) 
            {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right) 
            {
                parent_track[current->right] = current;
                q.push(current->right);
            } 
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        mark_parent(root,parent_track);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            if(curr_level==k) break;
            curr_level++;
            for(int i=0;i<size;i++)
            {
                TreeNode* current = q.front();q.pop();
                if( current->left && visited[current->left]==false)
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if( current->right && visited[current->right]==false)
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && visited[parent_track[current]]==false)
                {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* curr = q.front(); q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};
