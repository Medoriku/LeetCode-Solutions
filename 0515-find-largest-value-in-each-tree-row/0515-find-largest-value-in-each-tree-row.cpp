class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {}; // Handle the case of an empty tree

        vector<int> result; // To store the largest values in each row
        queue<TreeNode*> q; // Queue for BFS
        q.push(root);       // Start with the root node

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            int maxVal = INT_MIN;     // Initialize max value for this level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                maxVal =
                    max(maxVal, node->val); // Update max value for the level

                // Add child nodes to the queue for the next level
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            result.push_back(maxVal); // Store the maximum value of this level
        }

        return result;
    }
};
