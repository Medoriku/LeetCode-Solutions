class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // If both nodes are null, they are equivalent
        if (!root1 && !root2) return true;
        // If one of the nodes is null or values do not match, they are not equivalent
        if (!root1 || !root2 || root1->val != root2->val) return false;

        // Check both cases: without flipping and with flipping
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
