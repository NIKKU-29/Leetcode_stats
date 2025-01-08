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

    pair<int,int>solver(TreeNode* root)
    {   

        if(root==nullptr) return {0,0};

        auto left=solver(root->left);
        auto right=solver(root->right);

        int take= root->val + left.second + right.second;
        int notake= max(left.first,left.second) + max(right.first,right.second);

        return {take,notake};
    }

    int rob(TreeNode* root) {
        auto result=solver(root);
        return max(result.first,result.second);
    }
};