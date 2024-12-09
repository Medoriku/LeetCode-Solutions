class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: if the node is null, there is no path
        if (root == nullptr) {
            return false;
        }
        
        // If the node is a leaf, check if the path sum matches
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }
        
        // Recursive calls for left and right subtrees
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};
