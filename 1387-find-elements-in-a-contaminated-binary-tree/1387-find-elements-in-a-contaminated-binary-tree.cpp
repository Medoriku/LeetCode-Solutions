class FindElements {
private:
    std::unordered_set<int> values;

    // DFS to recover the tree and store values
    void recover(TreeNode* node, int val) {
        if (!node)
            return;
        node->val = val;
        values.insert(val);

        recover(node->left, 2 * val + 1);
        recover(node->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        if (root)
            recover(root, 0); // Start recovery from root with value 0
    }

    bool find(int target) { return values.count(target) > 0; }
};
