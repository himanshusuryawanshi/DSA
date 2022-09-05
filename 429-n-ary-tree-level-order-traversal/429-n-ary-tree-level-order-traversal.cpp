class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
      if(root == NULL) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.emplace_back();
            for (int i = q.size(); i >= 1; i--) {
                Node* curr = q.front(); q.pop();
                ans.back().push_back(curr->val);
                for (Node* child : curr->children) {
                    q.push(child);
                }
            }
        }
        return ans;   
    }
};