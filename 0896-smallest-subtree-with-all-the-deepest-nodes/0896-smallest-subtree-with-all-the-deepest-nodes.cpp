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

    TreeNode* solver(TreeNode* temp,int& depth)
    {
        if(!temp) return nullptr;

        int leftdepth=0;
        int rightdepth=0;
        TreeNode* left=solver(temp->left,leftdepth);
        TreeNode* right=solver(temp->right,rightdepth);

        depth=max(leftdepth,rightdepth)+1;
        //ha level pe depth calulate hogi taki make sure ho sake ki deppest balanced ya unbalanced ans hi return ho
        

        if(leftdepth==rightdepth) return temp; //balance hone pe node return matlab self return agar left aur right dono side barabar legth hai to hi khud ko return karo

        return leftdepth > rightdepth ? left : right; //otehwise check when hs more depth let or right
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth=0;
        return solver(root,depth);
    }
};