class Solution {
public:
    struct Result {
        TreeNode* node;
        int depth;
    };
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).node;
    }
    
    Result dfs(TreeNode* root) {
        if (!root) return {nullptr, 0};
        Result left = dfs(root->left);
        Result right = dfs(root->right);
        
        if (left.depth > right.depth) return {left.node, left.depth + 1};
        if (left.depth < right.depth) return {right.node, right.depth + 1};
        return {root, left.depth + 1};
    }
};
