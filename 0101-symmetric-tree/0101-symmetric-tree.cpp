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

    bool solver(TreeNode* t1 , TreeNode* t2)
    {
        if(t1==nullptr && t2==nullptr) return true;
        if(t1==nullptr || t2==nullptr || t1->val !=t2->val) return false;

        bool a=solver(t1->left,t2->right);
        bool b=solver(t1->right,t2->left);

        return a & b;
    }

    bool isSymmetric(TreeNode* root) {
        return solver(root->left,root->right);
    }
};