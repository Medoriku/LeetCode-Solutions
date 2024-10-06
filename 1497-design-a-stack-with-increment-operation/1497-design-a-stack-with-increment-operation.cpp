class CustomStack {
private:
    vector<int> stack;    // Stack to hold the elements
    vector<int> inc;      // Lazy increment array
    int maxSize;          // Maximum size of the stack
    
public:
    CustomStack(int maxSize) : maxSize(maxSize) {
        // Initialize the increment array with zeros, equal to the maximum size
        inc.resize(maxSize, 0);
    }
    
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        int index = stack.size() - 1;
        if (index == -1) {
            return -1; // Stack is empty
        }
        
        // Apply any pending increment to the top element
        int top = stack[index] + inc[index];
        
        // If there is a pending increment for this element, pass it down to the next element
        if (index > 0) {
            inc[index - 1] += inc[index];
        }
        
        // Clear the increment for this element
        inc[index] = 0;
        
        // Remove the top element from the stack
        stack.pop_back();
        
        return top;
    }
    
    void increment(int k, int val) {
        // Increment the bottom k elements by val
        // We only need to mark the increment for the (k-1)th element if it exists
        int limit = min(k, (int)stack.size()) - 1;
        if (limit >= 0) {
            inc[limit] += val;
        }
    }
};
