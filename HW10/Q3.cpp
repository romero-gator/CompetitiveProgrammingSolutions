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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // leaf node check
        if (root == NULL) {
            return NULL;
        }
        
        // root node is p or q, thus root is LCA
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left == NULL && right != NULL) { // p and q are on right subtree
            return right;
        } else if (left != NULL && right == NULL) { // p and q are on left subtree
            return left;
        } else if (left != NULL && right != NULL) { // p and q are on diff subtrees
            return root;
        } else {
            return NULL;
        }
    }
};