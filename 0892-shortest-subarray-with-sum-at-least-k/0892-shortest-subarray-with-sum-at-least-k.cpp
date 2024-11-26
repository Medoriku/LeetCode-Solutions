class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0); // Prefix sum array
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq;      // Monotonic deque
        int result = n + 1; // Initialize to an impossible large value

        for (int j = 0; j <= n; ++j) {
            // Check for valid subarray
            while (!dq.empty() && prefix[j] - prefix[dq.front()] >= k) {
                result = min(result, j - dq.front());
                dq.pop_front();
            }

            // Maintain monotonicity of deque
            while (!dq.empty() && prefix[j] <= prefix[dq.back()]) {
                dq.pop_back();
            }

            // Add current index to deque
            dq.push_back(j);
        }

        return result == n + 1 ? -1 : result;
    }
};
