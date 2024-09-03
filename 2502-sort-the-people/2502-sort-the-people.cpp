class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a vector of pairs (height, name)
        vector<pair<int, string>> heightNamePairs;
        for (int i = 0; i < heights.size(); ++i) {
            heightNamePairs.emplace_back(heights[i], names[i]);
        }

        // Sort the vector by height in descending order
        sort(heightNamePairs.begin(), heightNamePairs.end(),
             [](const pair<int, string>& a, const pair<int, string>& b) {
                 return a.first > b.first; // Sort by height in descending order
             });

        // Extract the sorted names
        vector<string> sortedNames;
        for (const auto& pair : heightNamePairs) {
            sortedNames.push_back(pair.second);
        }

        return sortedNames;
    }
};