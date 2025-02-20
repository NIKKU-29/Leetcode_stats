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

    void solver(TreeNode* &first,TreeNode* &second,TreeNode* &curr,TreeNode* &prev,TreeNode * &mid)
    {
        if(curr == nullptr) return;
        
        solver(first,second,curr->left,prev,mid);
        
        if(prev && curr->val < prev->val)
        {
            
                if(!first)
                {
                    first = prev;
                    mid = curr;
                            
                }
    
                
                else
                {
                    second = curr;
                }
                
        }
        
        prev=curr;
        
        solver(first,second,curr->right,prev,mid);
        
        
    }

    void recoverTree(TreeNode* root) {
        
        TreeNode * first = nullptr , *second = nullptr;
        TreeNode * prev = nullptr , * mid = nullptr;
            
            solver(first,second,root,prev,mid);
            
            if(first && second) swap(first->val , second -> val);
            else if( first && mid) swap(first -> val , mid ->val);

    }
};


