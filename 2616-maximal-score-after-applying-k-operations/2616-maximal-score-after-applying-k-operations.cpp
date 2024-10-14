class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Use a max-heap (simulated by negating values)
        priority_queue<int> maxHeap;

        // Push all elements into the max-heap
        for (int num : nums) {
            maxHeap.push(num);
        }

        long long score = 0;

        // Perform k operations
        for (int i = 0; i < k; ++i) {
            int maxElement = maxHeap.top();
            maxHeap.pop();
            score += maxElement;

            // Calculate the new value as ceil(maxElement / 3)
            int newElement = ceil(maxElement / 3.0);
            maxHeap.push(newElement);
        }

        return score;
    }
};