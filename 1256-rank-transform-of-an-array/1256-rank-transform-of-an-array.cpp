class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr; // Create a copy of the original array
        sort(sortedArr.begin(), sortedArr.end()); // Sort the array

        unordered_map<int, int>
            rankMap;  // Map to store the rank of each element
        int rank = 1; // Start ranking from 1

        // Iterate through the sorted array and assign ranks
        for (int i = 0; i < sortedArr.size(); ++i) {
            // If the current element is not already in the map, assign it a
            // rank
            if (rankMap.find(sortedArr[i]) == rankMap.end()) {
                rankMap[sortedArr[i]] = rank++;
            }
        }

        // Replace elements in the original array with their ranks
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rankMap[arr[i]];
        }

        return arr; // Return the transformed array with ranks
    }
};
