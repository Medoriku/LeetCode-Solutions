#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string result;

        for (char c : s) {
            int len = result.size();
            // Add the character only if it doesn't create three consecutive identical characters
            if (len < 2 || !(result[len - 1] == c && result[len - 2] == c)) {
                result += c;
            }
        }

        return result;
    }
};
