class Solution {
public:
    // Function to add two binary strings
    std::string addBinary(const std::string& a, const std::string& b) {
        std::string result = "";  // To store the result
        int carry = 0;  // To hold the carry during addition
        
        // Pointers for the two strings
        int i = a.size() - 1;
        int j = b.size() - 1;

        // Iterate while there are bits to process or there is a carry
        while (i >= 0 || j >= 0 || carry) {
            int bitA = (i >= 0) ? a[i--] - '0' : 0;  // Convert char to int
            int bitB = (j >= 0) ? b[j--] - '0' : 0;  // Convert char to int

            int sum = bitA + bitB + carry;  // Add bits and carry
            result += (sum % 2) + '0';  // Append the result bit
            carry = sum / 2;  // Calculate new carry
        }

        // The result is in reverse order, so we need to reverse it
        std::reverse(result.begin(), result.end());

        return result;  // Return the final binary sum
    }
};
