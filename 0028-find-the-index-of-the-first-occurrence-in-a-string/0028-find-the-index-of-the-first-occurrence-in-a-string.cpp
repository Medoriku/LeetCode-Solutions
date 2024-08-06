class Solution {
public:
    int strStr(string haystack, string needle) {
            // Find the first occurence of needle withing the haystack
            int i = haystack.find(needle);
            // Check if the occurence exists
            if (i != std::string::npos){
                return i;
            }
            else {
                return -1;
            }
        }
};