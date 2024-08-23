class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        for (int i = 0; i < s.length()-1; ++i){
            int ascii_value_1 = static_cast<int>(s[i]);
            int ascii_value_2 = static_cast<int>(s[i+1]);
            result += abs(ascii_value_1 - ascii_value_2);
        }
        return result;
    }
};