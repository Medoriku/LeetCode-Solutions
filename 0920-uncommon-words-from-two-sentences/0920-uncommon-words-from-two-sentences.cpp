class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;

        // Helper lambda to populate the map with words and their frequencies
        auto countWords = [&](string &s) {
            stringstream ss(s);  // Use stringstream to split by spaces
            string word;
            while (ss >> word) {
                wordCount[word]++;
            }
        };

        // Count words from both sentences
        countWords(s1);
        countWords(s2);

        // Collect uncommon words
        vector<string> result;
        for (const auto &entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};