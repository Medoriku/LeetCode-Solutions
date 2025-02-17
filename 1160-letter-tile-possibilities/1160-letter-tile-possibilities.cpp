#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int backtrack(std::unordered_map<char, int>& freqMap, int length) {
        int count = 0;

        for (auto& [ch, freq] : freqMap) {
            if (freq > 0) {
                // Use the letter
                freq--;
                count +=
                    1 + backtrack(freqMap, length + 1); // Count the sequence

                // Backtrack (restore the letter)
                freq++;
            }
        }

        return count;
    }

    int numTilePossibilities(std::string tiles) {
        std::unordered_map<char, int> freqMap;
        for (char ch : tiles) {
            freqMap[ch]++;
        }

        return backtrack(freqMap, 0);
    }
};
