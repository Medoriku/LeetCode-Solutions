class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1; // If the tree is empty, return -1

        std::vector<long long> levelSums; // To store sums of each level
        std::queue<TreeNode*> q; // Queue for BFS
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            long long currentLevelSum = 0;

            // Calculate the sum for the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelSum += node->val;

                // Add child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levelSums.push_back(currentLevelSum);
        }

        // Sort the level sums in descending order
        std::sort(levelSums.rbegin(), levelSums.rend());

        // Check if there are at least k levels
        if (k > levelSums.size()) {
            return -1; // Not enough levels
        }

        return levelSums[k - 1]; // Return the k-th largest level sum
    }
};