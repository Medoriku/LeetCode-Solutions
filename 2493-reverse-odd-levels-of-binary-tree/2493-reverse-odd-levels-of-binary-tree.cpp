class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root)
            return root;

        // BFS setup
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodes; // To store nodes of the current level

            // Collect all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node);

                // Add children to the queue for the next level
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Reverse values if the level is odd
            if (level % 2 == 1) {
                int left = 0, right = nodes.size() - 1;
                while (left < right) {
                    swap(nodes[left]->val, nodes[right]->val);
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root;
    }
};
