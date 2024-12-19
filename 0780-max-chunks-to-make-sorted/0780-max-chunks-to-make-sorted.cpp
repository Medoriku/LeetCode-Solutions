class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int maxSoFar = 0;

        for (int i = 0; i < arr.size(); i++) {
            maxSoFar = max(maxSoFar, arr[i]);
            // If the maximum value equals the current index, we can form a
            // chunk
            if (maxSoFar == i) {
                chunks++;
            }
        }

        return chunks;
    }
};
