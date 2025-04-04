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

    TreeNode* solver(TreeNode* temp, int&depth)
    {
        if(!temp) return nullptr;

        int leftdepth = 0;
        int rightdepth = 0;

        TreeNode * left = solver(temp->left,leftdepth);
        TreeNode * right = solver(temp->right,rightdepth);

        depth = max(leftdepth,rightdepth) + 1;

        if(leftdepth == rightdepth) return temp;

        return leftdepth > rightdepth ? left : right;
    }


    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = 0;
        return solver(root,depth);
    }
};