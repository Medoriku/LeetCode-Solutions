class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seenNumbers;

        while (n != 1 && seenNumbers.find(n) == seenNumbers.end()) {
            seenNumbers.insert(n);
            string digits = to_string(n);
            int square = 0;

            for (char digit : digits) {
                digit = digit - '0';
                square += digit * digit;
            }
            n = square;
        }
        return n == 1;
    }
};