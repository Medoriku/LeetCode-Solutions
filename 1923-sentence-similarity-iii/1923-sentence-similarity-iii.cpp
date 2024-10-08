class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split the sentences into words
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        // Ensure that words1 is the shorter sentence
        if (words1.size() > words2.size()) {
            swap(words1, words2);
        }
        
        int n1 = words1.size();
        int n2 = words2.size();
        
        int i = 0, j = 0;
        
        // Find the longest common prefix
        while (i < n1 && words1[i] == words2[i]) {
            ++i;
        }
        
        // Find the longest common suffix
        while (j < n1 && words1[n1 - j - 1] == words2[n2 - j - 1]) {
            ++j;
        }
        
        // Check if the common prefix + suffix cover all of the shorter sentence
        return i + j >= n1;
    }
    
private:
    // Helper function to split a sentence into words
    vector<string> split(const string& sentence) {
        istringstream ss(sentence);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
};
