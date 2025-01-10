class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26,
                            0); // Maximum frequency of each character in words2

        // Step 1: Compute aggregate requirements from words2
        for (const string& b : words2) {
            vector<int> freq(26, 0);
            for (char c : b) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> result;

        // Step 2: Check each word in words1
        for (const string& a : words1) {
            vector<int> freq(26, 0);
            for (char c : a) {
                freq[c - 'a']++;
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                result.push_back(a);
            }
        }

        return result;
    }
};
