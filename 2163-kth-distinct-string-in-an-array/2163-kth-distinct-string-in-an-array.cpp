class Solution {
public:
    std::string kthDistinct(std::vector<std::string>& arr, int k) {
        std::unordered_map<std::string, int> frequency;
        std::vector<std::string> uniques;

        // Count the frequency of each element in the array
        for (const auto& str : arr) {
            frequency[str]++;
        }

        // Collect elements that appear exactly once
        for (const auto& str : arr) {
            if (frequency[str] == 1) {
                uniques.push_back(str);
            }
        }

        // Check if there are at least k distinct elements
        if (k > uniques.size() || k <= 0) {
            return "";
        }

        return uniques[k - 1]; // Return the k-th distinct element (1-based index)
    }
};
