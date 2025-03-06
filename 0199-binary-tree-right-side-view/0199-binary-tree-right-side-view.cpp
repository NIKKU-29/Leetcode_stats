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

    vector<int> rightSideView(TreeNode* root) {
            vector<int>ans;
            if(root == nullptr) return {};
            
            queue<TreeNode*>q;
            q.push(root);


            while(!q.empty())
            {
                int siz=q.size();
                vector<int>curr;
                
                while(siz--)
                {
                    TreeNode* Tp=q.front();
                    q.pop();

                    curr.push_back(Tp->val);
                    if(Tp->left) q.push(Tp->left);
                    if(Tp->right) q.push(Tp->right);

                }

                ans.push_back(curr.back());
            }

            return ans;
    }
};