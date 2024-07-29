class Solution {
public:
    bool isPalindrome(int x) {
        // Convert the integer to string
        string x_string = std::to_string(x);
        int left = 0;
        int right = x_string.size() - 1;

        // While the left side digit index value is less than the right side digit index value, check if they are equal and return false if they are not, true in other cases
        while (left < right){
            if (x_string[left] != x_string[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};