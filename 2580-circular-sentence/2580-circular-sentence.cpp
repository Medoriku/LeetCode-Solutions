
class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Split the sentence into words
        stringstream ss(sentence);
        string word;
        vector<string> words;
        
        // Push each word into a vector
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Check the circular condition
        int n = words.size();
        
        // Check adjacent words
        for (int i = 0; i < n - 1; ++i) {
            if (words[i].back() != words[i + 1].front()) {
                return false;
            }
        }
        
        // Check the first and last word
        if (words[n - 1].back() != words[0].front()) {
            return false;
        }
        
        return true;
    }
};
