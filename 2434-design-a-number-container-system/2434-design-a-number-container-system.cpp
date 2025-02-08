class NumberContainers {
public:
    // Map to store each number and a set of indices where the number is present
    unordered_map<int, set<int>> container;
    unordered_map<int, int> index_map; // To store the current number at a given index

    NumberContainers() {
        // Initialize the number container system
    }
    
    void change(int index, int number) {
        // If the index already has a number, remove it from its old set
        if (index_map.find(index) != index_map.end()) {
            int old_number = index_map[index];
            container[old_number].erase(index); // Remove index from the old number set
        }

        // Add the new number at the given index
        index_map[index] = number;
        container[number].insert(index); // Insert the index in the new number's set
    }
    
    int find(int number) {
        // If the number exists in the container and has at least one index
        if (container.find(number) != container.end() && !container[number].empty()) {
            return *container[number].begin(); // Get the smallest index
        }
        
        // If the number doesn't exist, return -1
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
