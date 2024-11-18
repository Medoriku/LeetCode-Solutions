

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) {
            return result; // All elements are replaced with 0.
        }

        int start, end, step;
        if (k > 0) {
            start = 1; // Start from the next element
            end = k;   // Include the next k elements
            step = 1;
        } else {
            start = -1; // Start from the previous element
            end = k;    // Include the previous |k| elements
            step = -1;
        }

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = start; j != end + step; j += step) {
                int index = (i + j + n) % n; // Handle circular indexing
                sum += code[index];
            }
            result[i] = sum;
        }

        return result;
    }
};
