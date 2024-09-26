class Solution {
public:
    int findKthNumber(int n, int k) {
        // Helper function to count the steps between cur and the next node at the same level
        auto count_steps = [](int cur, int n) {
            long long steps = 0;
            long long first = cur;
            long long last = cur;
            while (first <= n) {
                steps += min((long long)n + 1, last + 1) - first;
                first *= 10;
                last = last * 10 + 9;
            }
            return steps;
        };
        
        int cur = 1;  // Start with 1, as the smallest number in lexicographical order
        k--;          // We want the k-th number, so reduce k by 1 to start from 0
        
        while (k > 0) {
            int steps = count_steps(cur, n);
            if (steps <= k) {
                // If the number of steps is less than or equal to k,
                // it means the k-th number is not in the subtree starting with `cur`
                k -= steps;
                cur++;  // Move to the next number in lexicographical order
            } else {
                // If k is within the current subtree, go deeper
                cur *= 10;  // Move to the next level in the lexicographical tree
                k--;        // We've already accounted for cur itself
            }
        }
        
        return cur;
    }
};
