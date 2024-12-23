class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root)
            return 0;

        // Step 1: Perform level-order traversal to group nodes by level
        std::vector<std::vector<int>> levels;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            std::vector<int> currentLevel;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            levels.push_back(currentLevel);
        }

        // Step 2: Calculate the minimum swaps required for each level
        int totalSwaps = 0;
        for (const auto& level : levels) {
            totalSwaps += minSwapsToSort(level);
        }

        return totalSwaps;
    }

private:
    int minSwapsToSort(const std::vector<int>& nums) {
        // Create an array of pairs (value, original_index)
        std::vector<std::pair<int, int>> arr;
        for (int i = 0; i < nums.size(); ++i) {
            arr.emplace_back(nums[i], i);
        }

        // Sort the array by value
        std::sort(arr.begin(), arr.end());

        // Count the cycles to find the minimum number of swaps
        std::vector<bool> visited(nums.size(), false);
        int swaps = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (visited[i] || arr[i].second == i)
                continue; // Already in place or visited

            // Count the size of the cycle
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second; // Move to the next index in the cycle
                ++cycleSize;
            }

            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
};
