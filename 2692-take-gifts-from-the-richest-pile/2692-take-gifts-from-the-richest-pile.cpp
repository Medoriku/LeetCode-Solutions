class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for (int i = 0; i < k; i++) {
            auto maxIt = max_element(
                gifts.begin(), gifts.end()); // Get iterator to max element
            *maxIt = (int)floor(
                sqrt(*maxIt)); // Dereference the iterator and update the value
        }
        long long sum = 0;
        for (int num : gifts) {
            sum += num;
        }
        return sum;
    }
};
