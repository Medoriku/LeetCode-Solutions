class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        // Loop through integers from the end of the vector
        for (int i = n-1; i >= 0; --i) {
            // Check if the digits are less than 9 and if so add 1
            if (digits[i] < 9){
                digits[i] += 1;
                return digits;
            }

            // If the digit is 9 set it to 0
            digits[i] = 0;
        } 

        // Insert 1 at the beginning of the vector if the last digit is 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};