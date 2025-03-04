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

    void solver(TreeNode* root)
    {
        

        queue<TreeNode*>q;
        q.push(root);
        int level=0;


        while(!q.empty())
        {
            int size = q.size();
            vector<int>curr;

            while(size--)
            {
                TreeNode* temp= q.front();
                q.pop();

                curr.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            if(level%2) reverse(curr.begin(),curr.end());

             ans.push_back(curr);
             level++;

        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return ans;
        
        solver(root);
        return ans;
    }
};