class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (char ch : columnTitle) {
            // Shift previous result left by multiplying by 26 and add the
            // current letter's value
            result = result * 26 + (ch - 'A' + 1);
        }

        return result;
    }
};