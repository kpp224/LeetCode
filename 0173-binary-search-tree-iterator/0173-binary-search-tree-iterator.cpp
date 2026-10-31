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
class BSTIterator {
    TreeNode *curr;
public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        int res = -1;

        while(curr) {
            if(!curr -> left) {
                res = curr -> val;
                curr = curr -> right;
                break;
            } else {
                auto prev = curr -> left;

                while(prev -> right && prev -> right != curr) {
                    prev = prev -> right;
                }

                if(!prev -> right) {
                    prev -> right = curr;
                    curr = curr -> left;
                } else {
                    res = curr -> val;
                    prev -> right = nullptr;
                    curr = curr -> right;
                    break;
                }
            }

        }

        return res;
    }
    
    bool hasNext() {
        return curr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */