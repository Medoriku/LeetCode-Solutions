class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0; // Handle edge case where the tree is empty
        
        // Queue for BFS traversal, starting with the root node
        std::queue<TreeNode*> q;
        q.push(root);
        
        int maxSum = INT_MIN;  // Store the maximum sum of any level
        int maxLevel = 0;      // Store the level with the maximum sum
        int currentLevel = 0;  // Track the current level
        
        // Perform level-order traversal (BFS)
        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            int levelSum = 0;         // Sum of values at the current level
            currentLevel++;           // Increment the level count
            
            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Add the node's value to the current level sum
                levelSum += node->val;
                
                // Enqueue left and right children for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Update maxSum and maxLevel if a larger sum is found
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currentLevel;
            }
        }
        
        // Return the level with the maximum sum
        return maxLevel;
    }
};
