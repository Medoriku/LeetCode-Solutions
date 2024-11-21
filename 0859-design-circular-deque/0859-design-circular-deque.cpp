class MyCircularDeque {
public:
    vector<int> deque;
    int front, rear, size, capacity;

    // Constructor to initialize the deque with a maximum size k
    MyCircularDeque(int k) {
        deque.resize(k);  // create a vector with size k
        front = 0;        // front pointer
        rear = 0;         // rear pointer
        size = 0;         // current size of the deque
        capacity = k;     // max size of the deque
    }

    // Insert at the front of the deque
    bool insertFront(int value) {
        if (isFull()) return false; // Cannot insert if deque is full
        front = (front - 1 + capacity) % capacity;  // Move front pointer
        deque[front] = value; // Insert value
        size++;
        return true;
    }

    // Insert at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) return false; // Cannot insert if deque is full
        deque[rear] = value; // Insert value
        rear = (rear + 1) % capacity; // Move rear pointer
        size++;
        return true;
    }

    // Delete the front element
    bool deleteFront() {
        if (isEmpty()) return false; // Cannot delete if deque is empty
        front = (front + 1) % capacity; // Move front pointer
        size--;
        return true;
    }

    // Delete the rear element
    bool deleteLast() {
        if (isEmpty()) return false; // Cannot delete if deque is empty
        rear = (rear - 1 + capacity) % capacity; // Move rear pointer
        size--;
        return true;
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) return -1; // Return -1 if deque is empty
        return deque[front];
    }

    // Get the rear element
    int getRear() {
        if (isEmpty()) return -1; // Return -1 if deque is empty
        return deque[(rear - 1 + capacity) % capacity];
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the deque is full
    bool isFull() {
        return size == capacity;
    }
};
