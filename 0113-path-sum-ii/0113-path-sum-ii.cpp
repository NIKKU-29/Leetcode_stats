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

    vector<vector<int>>ans;

    void solver(TreeNode* root, int target ,vector<int>&curr)
    {
        if(!root) return;
 
        curr.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr && target == root->val)
        {
            ans.push_back(curr);
        }

        else{
            solver(root->left,target - root->val,curr);
            solver(root->right,target - root->val,curr);
        }

        curr.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        ans.clear();
        vector<int>curr;
        solver(root,targetSum,curr);
        return ans;

    }
};