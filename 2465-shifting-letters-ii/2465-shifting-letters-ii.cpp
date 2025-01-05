class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0); // Difference array for shifts

        // Populate the difference array
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int delta = (direction == 1) ? 1 : -1;
            diff[start] += delta;
            if (end + 1 < n) {
                diff[end + 1] -= delta;
            }
        }

        // Compute the prefix sum to get the net shift for each character
        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += diff[i];
            // Normalize the shift to ensure it's within [0, 26)
            int shift = (netShift % 26 + 26) % 26;
            // Apply the shift to the character
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};
