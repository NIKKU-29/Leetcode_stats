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

    vector<int>ans;

    void solver(TreeNode* root,unordered_map<TreeNode*, vector<TreeNode*>>&adj)
    {
        if(root == nullptr) return;

        if(root->left) 
        {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            solver(root->left,adj);
        }

        if(root->right)
        {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            solver(root->right,adj);           
        }

    }

    void findkdist(unordered_map<TreeNode*, vector<TreeNode*>>&adj,TreeNode* target,int k)
    {
        queue<TreeNode*>q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);

        int level=0;

        while(!q.empty())
        {
            int size = q.size(); 
            level++;
            if(level > k) break;

            while(size--)
            {
                TreeNode* T = q.front();
                q.pop();
                

                for(auto elem : adj[T])
                {
                    if (!visited.count(elem))
                    {
                        if(level == k)
                        {
                            ans.push_back(elem->val);
                        }

                        q.push(elem);
                        visited.insert(elem);

                    }
                }
            }

        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        if(k==0) return {target->val};
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        solver(root,adj);
        findkdist(adj,target,k);
        return ans;
    }
};