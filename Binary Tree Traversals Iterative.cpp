// Preorder Traversal

void iterative_Preorder(node* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty stack and push root to it
    stack<node*> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
        struct node* node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}


//Inorder Traversal

void inOrder_iterative(node *root)
{
    stack<node *> s;
    node *curr = root;
  
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }
  
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
  
        cout << curr->data << " ";
  
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
  
    } /* end of while */
}


//PostOrder Traversal

//1. Using Two Stack
void postOrderIterative(Node* root)
{
    if (root == NULL)
        return;
 
    // Create two stacks
    stack<Node *> s1, s2;
 
    // push root to first stack
    s1.push(root);
    Node* node;
 
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);
 
        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
 
    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

//2.. Using One Stack
vector<int> postOrderIterative(struct node* root)
{
    vector<int> postOrderList;
    // Check for empty tree
    if (root == NULL)
        return postOrderList;
    stack<node*> S;
    S.push(root);
    node* prev = NULL;
    while (!S.empty()) {
        auto current = S.top();
        /* go down the tree in search of a leaf an if so
           process it and pop stack otherwise move down */
        if (prev == NULL || prev->left == current
            || prev->right == current) {
            if (current->left)
                S.push(current->left);
            else if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }
            /* go up the tree from left node, if the child
               is right push it onto stack otherwise process
               parent and pop stack */
        }
 
        else if (current->left == prev) {
            if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }
 
            /* go up the tree from right node and after
            coming back from right node process parent and
            pop stack */
        }
        else if (current->right == prev) {
            S.pop();
            postOrderList.push_back(current->data);
        }
        prev = current;
    }
    return postOrderList;
}

//3. Using Stack and Hashing

vector<int> postOrder(Node* node)
{
    stack<Node*> s;
 
    // vector to store the postorder traversal
    vector<int> post;
 
    // Using unordered map as hash table for hashing to mark
    // the visited nodes
    unordered_map<Node*, int> vis;
 
    // push the root node in the stack to traverse the tree
    s.push(node);
 
    // stack will be empty when traversal is completed
    while (!s.empty()) {
 
        // mark the node on the top of stack as visited
        vis[s.top()] = 1;
 
        // if left child of the top node is not NULL and not
        // visited push it into the stack
        if (s.top()->left != 0) {
            if (!vis[s.top()->left]) {
                s.push(s.top()->left);
                continue;
            }
        }
 
        // Otherwise if the right child of the top node is
        // not NULL and not visited push it into the stack
        if (s.top()->right != 0) {
            if (!vis[s.top()->right]) {
                s.push(s.top()->right);
                continue;
            }
        }
 
        // Add the value of the top node in our postorder
        // traversal answer if none of the above two
        // conditions are met
        post.push_back(s.top()->data);
 
        // Remove the top node from the stack
        s.pop();
    }
 
    // post will now contain the postorder traversal of the
    // tree
    return post;
}
