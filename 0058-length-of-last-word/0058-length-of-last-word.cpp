void splitString (string text, vector <string> &words){
    string word;
    // Loop throught the characters in text to form the vector of words
    for(char c : text){
        // If character equals space, and the word is not empty then end the word
        if (c == ' '){
            if (!word.empty()){
                words.push_back(word);
                word.clear();
            }
        }
        // Otherwise add the characters to word
        else {
            word += c;
        }
    }
    // If the word is not empty append it to the words vector to store
    if (!word.empty()){
        words.push_back(word);
    }
}



class Solution {
public:
    int lengthOfLastWord(string s) {
        vector <string> words;
        // Split the string of characters into a vector of words
        splitString(s, words);
        // Find the last word and return its length
        string lastWord = words.back();
        int lastWordCount = lastWord.length();
        return lastWordCount;    
        }
};