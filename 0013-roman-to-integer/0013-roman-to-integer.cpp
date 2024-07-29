class Solution {
public:
    // Define map for conversions
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
    // Loop through the elements given in a string, convert the elements to integers, check if the element is at the end of the string and check if the element following the current one's conversion to an integer is lareger than the element itself's. If so, subtract the current element's conversion to an integer from the result. If that is not the case, add the integer to the result
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