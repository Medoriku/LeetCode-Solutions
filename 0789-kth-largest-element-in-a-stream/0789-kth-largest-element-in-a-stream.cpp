#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        // Initialize the min-heap with the first k elements or fewer
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        // Add the new value to the heap
        if (minHeap.size() < k_) {
            minHeap.push(val);  // If the heap has fewer than k elements, add the new value
        } else if (val > minHeap.top()) {
            minHeap.pop();  // Remove the smallest element
            minHeap.push(val);  // Add the new value
        }
        
        // The k-th largest element is the smallest element in the min-heap
        return minHeap.top();
    }

private:
    int k_;
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to store the k largest elements
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */