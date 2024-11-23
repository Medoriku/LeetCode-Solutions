class Solution {
public:
    string intToRoman(int num) {
        // Step 1: Define the Roman numeral mappings
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string result = ""; // Resultant Roman numeral
        
        // Step 2: Iterate through the mapping
        for (const auto& [value, symbol] : roman) {
            // Append the symbol as many times as possible
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};
