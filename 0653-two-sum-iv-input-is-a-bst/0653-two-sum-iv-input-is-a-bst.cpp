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


bool solver(TreeNode* root , set<int>&st,int target)
    {
        if(root == nullptr) return false;
        
        int value=(target - root->val);
        
        if(st.count(value))
        {
            return true;
        }
        
        st.insert(root->val);
        return solver(root->left,st,target)  || solver(root->right,st,target);
    
        
    }
    bool findTarget(TreeNode* root, int k) {
         set<int>st;
        return solver(root,st,k);
    }
};