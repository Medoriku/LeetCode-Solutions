class Solution {
public:
    int myAtoi(std::string s) {
        long long number = 0; // Use long long to handle larger numbers
        int sign = 1;
        bool hasDigits = false;
        bool signHandled = false;

        int i = 0;
        // Skip leading spaces
        while (i < s.size() && s[i] == ' ') {
            ++i;
        }

        // Handle sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            signHandled = true;
            ++i;
        }

        // Process digits
        while (i < s.size() && isdigit(s[i])) {
            hasDigits = true;
            number = number * 10 + (s[i] - '0');
            
            // Check for overflow/underflow
            if (number > INT_MAX) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            ++i;
        }

        // If no digits were found, return 0
        if (!hasDigits) {
            return 0;
        }

        number *= sign;

        // Ensure the final number is within the 32-bit integer range
        if (number > INT_MAX) {
            return INT_MAX;
        } else if (number < INT_MIN) {
            return INT_MIN;
        }

        return static_cast<int>(number);
    }
};
