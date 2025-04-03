class Solution {
public:

    TreeNode* findMin(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Fix: Assign back
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Fix: Assign back
        } else {
            // Case 1 & 2: Node has 0 or 1 child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp; // Fix: Return the correct child
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp; // Fix: Return the correct child
            }

            // Case 3: Node has 2 children → Find inorder successor
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};
