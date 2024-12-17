class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Step 1: Count frequencies of each character
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Build the result string
        string result = "";
        int prevChar = -1; // Previous character used
        int repeatCount =
            0; // How many times the previous character was used in a row

        for (int i = 25; i >= 0;
             --i) { // Iterate from highest to lowest character
            while (freq[i] > 0) {
                if (prevChar == i && repeatCount == repeatLimit) {
                    // Find next available character
                    bool switched = false;
                    for (int j = i - 1; j >= 0; --j) {
                        if (freq[j] > 0) {
                            result += (char)('a' + j);
                            freq[j]--;
                            prevChar = j;
                            repeatCount = 1;
                            switched = true;
                            break;
                        }
                    }
                    if (!switched)
                        return result; // No valid characters left
                } else {
                    // Add current character
                    result += (char)('a' + i);
                    freq[i]--;
                    if (prevChar == i) {
                        repeatCount++;
                    } else {
                        prevChar = i;
                        repeatCount = 1;
                    }
                }
            }
        }
        return result;
    }
};
