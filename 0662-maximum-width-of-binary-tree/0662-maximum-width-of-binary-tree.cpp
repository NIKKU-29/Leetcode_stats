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

    int maxi;
    typedef pair<TreeNode*,int> p;
    void solver(TreeNode* root)
    {
        queue<p>q;
        q.push({root,0});

        while(!q.empty())
        {
            int siz=q.size();
            maxi=max(maxi, q.back().second - q.front().second + 1);
            while(siz--)
            {
                TreeNode* node = q.front().first;
                int idx = q.front().second;
                q.pop();


                if(node->left)q.push({node->left,2*idx + 1});
                if(node->right)q.push({node->right,2*idx + 2});
            }
        }
    }

    int widthOfBinaryTree(TreeNode* root) {
        solver(root);
        return maxi;
    }
};