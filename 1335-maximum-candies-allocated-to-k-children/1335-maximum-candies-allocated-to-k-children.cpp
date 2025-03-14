class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int c : candies) {
            count += c / mid; // Count how many children can get `mid` candies
        }
        return count >= k; // We must serve at least `k` children
    }

    int maximumCandies(vector<int>& candies, long long k) {
        if (accumulate(candies.begin(), candies.end(), 0LL) < k)
            return 0; // Not enough candies

        int left = 1, right = *max_element(candies.begin(), candies.end());
        int res = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(candies, k, mid)) {
                res = mid; // `mid` is possible, try a larger value
                left = mid + 1;
            } else {
                right =
                    mid - 1; // Reduce `mid` if `k` children cannot be served
            }
        }

        return res;
    }
};
