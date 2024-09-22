class Solution {
public:
    int compareVersion(string version1, string version2) {
        // Split the version strings by the dot '.'
        istringstream v1Stream(version1);
        istringstream v2Stream(version2);
        string v1Part, v2Part;

        while (true) {
            // Get the next revision part from each version
            if (!getline(v1Stream, v1Part, '.')) v1Part = "0"; // If no more parts, use "0"
            if (!getline(v2Stream, v2Part, '.')) v2Part = "0"; // If no more parts, use "0"

            // Convert to integers (ignoring leading zeros)
            int v1Value = stoi(v1Part);
            int v2Value = stoi(v2Part);

            // Compare the current revision values
            if (v1Value < v2Value) return -1;
            if (v1Value > v2Value) return 1;

            // If both parts are equal, continue to the next revision
            if (v1Stream.eof() && v2Stream.eof()) break; // Both versions are fully processed
        }

        return 0; // Both versions are equal
    }
};
