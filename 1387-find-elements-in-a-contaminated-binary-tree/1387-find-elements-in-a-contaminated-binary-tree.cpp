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
class FindElements {
public:

    unordered_set<int>st;
     void solver(TreeNode* root, int ParentValue)
     {
        if(!root) return;

        st.insert(ParentValue);
        solver(root->left,ParentValue * 2 + 1);
        solver(root->right,ParentValue * 2 + 2);

        return;
     }

    FindElements(TreeNode* root) {
        solver(root,0);
    }
    
    bool find(int target) {
        if(st.count(target)) return true;
        else return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */