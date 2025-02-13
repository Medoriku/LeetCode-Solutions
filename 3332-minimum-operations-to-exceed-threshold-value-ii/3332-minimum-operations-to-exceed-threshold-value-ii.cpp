#include <queue>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::priority_queue<long long, std::vector<long long>,
                            std::greater<long long>>
            minHeap(nums.begin(), nums.end());
        int operations = 0;

        while (minHeap.top() < k) {
            if (minHeap.size() < 2)
                break; // Ensures at least two elements exist

            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();

            long long new_num =
                2 * std::min(x, y) + std::max(x, y); // Prevent overflow
            minHeap.push(new_num);
            operations++;
        }

        return operations;
    }
};