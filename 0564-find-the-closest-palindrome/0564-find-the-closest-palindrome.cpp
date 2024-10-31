class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        
        // Edge case for single digit number
        if (num <= 10) {
            return to_string(num - 1);
        }
        
        // Candidates to consider
        vector<long long> candidates;
        
        // Case 1: Construct palindrome by mirroring the first half
        string firstHalf = n.substr(0, (len + 1) / 2);
        candidates.push_back(getPalindrome(firstHalf, len % 2 == 0));
        
        // Case 2: Construct palindrome by incrementing the first half
        long long incrementedHalf = stoll(firstHalf) + 1;
        candidates.push_back(getPalindrome(to_string(incrementedHalf), len % 2 == 0));
        
        // Case 3: Construct palindrome by decrementing the first half
        long long decrementedHalf = stoll(firstHalf) - 1;
        candidates.push_back(getPalindrome(to_string(decrementedHalf), len % 2 == 0));
        
        // Edge cases for boundaries
        candidates.push_back((long long)pow(10, len - 1) - 1);  // e.g., 999...999
        candidates.push_back((long long)pow(10, len) + 1);      // e.g., 1000...0001
        
        // Find the closest palindrome
        long long closest = -1;
        for (long long candidate : candidates) {
            if (candidate != num) {
                if (closest == -1 ||
                    abs(candidate - num) < abs(closest - num) ||
                    (abs(candidate - num) == abs(closest - num) && candidate < closest)) {
                    closest = candidate;
                }
            }
        }
        
        return to_string(closest);
    }
    
private:
    // Helper function to create a palindrome based on the left half
    long long getPalindrome(const string& leftHalf, bool isEven) {
        string palindrome = leftHalf;
        int start = isEven ? leftHalf.size() - 1 : leftHalf.size() - 2;
        for (int i = start; i >= 0; --i) {
            palindrome += leftHalf[i];
        }
        return stoll(palindrome);
    }
};