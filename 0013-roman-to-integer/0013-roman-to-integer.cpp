class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> conversion = {
        {'I', 1},
        {'V', 5}, 
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int result = 0;
    for (int i = 0; i < s.length(); ++ i) {
        int current = conversion[s[i]];
        if (i<s.length()-1 && conversion[s[i+1]] > conversion[s[i]] ){
            result = result - conversion[s[i]];
        }
        else{
            result += conversion[s[i]];
        }
    }

    return result;
    }

};