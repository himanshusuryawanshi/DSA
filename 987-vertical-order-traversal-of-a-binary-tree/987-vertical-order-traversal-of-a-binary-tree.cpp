class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        map<int, map<int, multiset<int> > > value;
        //for specific vertical,there could be a level where there are more
        //than one node,that's why we have to carry a set DS to store if that 
        //condition arises. 
        queue< pair<TreeNode*, pair<int,int> > > q;  
        //pushing node and it's coordinate q-> ({{node},vertical,level})
        
        q.push( {root, {0,0}} ); //pushing root node and assuming it as it is located at origin.so pushing root and co- 
        //ordinate (0,0)
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
                q.push({frontnode->left, {vertical-1, level+1}}); //while moving left node,we have to move downward in                     level and also have to move leftwards so we have to decrease vertical
            }
            if(frontnode->right)
            {
                q.push({frontnode->right, {vertical+1, level+1}}); //while moving right node,we have to move downward in level and have to move rightwards in vertical so have to increase vertical also.
            }
        }
        // traversing whole map for printing all the node value vertical wise 
        for(auto p: value)
        {
            vector<int> level;
            for(auto q: p.second)
            {
                level.insert(level.end(), q.second.begin(),q.second.end()); //printing all node vertical wise
            }
            ans.push_back(level);
        }
        return ans;
    }
};