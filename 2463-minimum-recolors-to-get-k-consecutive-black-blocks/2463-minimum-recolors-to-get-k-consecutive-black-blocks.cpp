class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minRecolors = k; // Maximum possible recolors needed
        int whiteCount = 0;

        // Count 'W' in the first k-length window
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W')
                whiteCount++;
        }

        minRecolors = whiteCount; // Set initial minimum

        // Slide the window across the string
        for (int i = k; i < blocks.size(); i++) {
            // Remove the leftmost character
            if (blocks[i - k] == 'W')
                whiteCount--;
            // Add the new character
            if (blocks[i] == 'W')
                whiteCount++;

            // Update the minimum recolors needed
            minRecolors = min(minRecolors, whiteCount);
        }

        return minRecolors;
    }
};
