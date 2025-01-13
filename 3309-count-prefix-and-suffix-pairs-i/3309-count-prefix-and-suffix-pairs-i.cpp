class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        // Helper function to check prefix and suffix
        auto isPrefixAndSuffix = [](const string& str1, const string& str2) {
            int len1 = str1.size();
            int len2 = str2.size();

            // str1 must be shorter than or equal to str2
            if (len1 > len2)
                return false;

            // Check if str1 is a prefix of str2
            if (str2.substr(0, len1) != str1)
                return false;

            // Check if str1 is a suffix of str2
            if (str2.substr(len2 - len1, len1) != str1)
                return false;

            return true;
        };

        // Iterate through all pairs (i, j) where i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};
