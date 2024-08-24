class Solution {
public:
    int longestPalindrome(std::string s) {
        std::unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        
        int length = 0;
        bool oddCountFound = false;
        
        for (auto& pair : charCount) {
            int count = pair.second;
            if (count % 2 == 0) {
                length += count;  // Add even counts directly.
            } else {
                length += count - 1;  // Add the largest even number less than the count.
                oddCountFound = true;
            }
        }
        
        if (oddCountFound) {
            length += 1;  // If there was an odd count, we can place one odd character in the center.
        }
        
        return length;
    }
};
