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
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {

//         if(root==nullptr) return nullptr;

//         TreeNode* temp=root->left;
//         root->left=root->right;
//         root->right=temp;

//         invertTree(root->left);
//         invertTree(root->right);


//         return root;
        
//     }
// };

class Solution{
    public: 
        TreeNode* invertTree(TreeNode* root) {

            if(root==nullptr) return nullptr;

            stack<TreeNode*>st;
            st.push(root);


            while(!st.empty())
            {
                TreeNode* node=st.top();
                st.pop();

                TreeNode* temp=node->left;
                node->left=node->right;
                node->right=temp;

                if(node->left!=nullptr) st.push(node->left);
                if(node->right!=nullptr) st.push(node->right);

            }

        return root;

    }
};