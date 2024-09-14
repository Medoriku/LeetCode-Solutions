class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // Create a frequency map for characters in 'chars'
        vector<int> char_count(26, 0);
        for (char c : chars) {
            char_count[c - 'a']++;
        }
        
        int length = 0;
        
        // Iterate through each word in the 'words' vector
        for (const string& word : words) {
            // Create a frequency map for characters in the current word
            vector<int> word_count(26, 0);
            for (char c : word) {
                word_count[c - 'a']++;
            }
            
            // Check if the word can be formed using characters from 'chars'
            bool can_form = true;
            for (int i = 0; i < 26; ++i) {
                if (word_count[i] > char_count[i]) {
                    can_form = false;
                    break;
                }
            }
            
            // If the word can be formed, add its length to 'length'
            if (can_form) {
                length += word.length();
            }
        }
        
        return length;
    }
};
