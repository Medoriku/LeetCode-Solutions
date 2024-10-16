class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max-heap to store (count, character) tuples
        priority_queue<pair<int, char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";

        while (!pq.empty()) {
            // Get the most frequent character
            auto [count1, char1] = pq.top();
            pq.pop();

            // Add the most frequent character to the result
            if (result.size() >= 2 && result.back() == char1 && result[result.size() - 2] == char1) {
                // If adding char1 causes three consecutive characters, we need the next best option
                if (pq.empty()) break;  // No other characters available to use

                auto [count2, char2] = pq.top();
                pq.pop();

                result += char2;
                if (--count2 > 0) pq.push({count2, char2});

                // Push back char1 into the heap for future use
                pq.push({count1, char1});
            } else {
                result += char1;
                if (--count1 > 0) pq.push({count1, char1});
            }
        }

        return result;
    }
};
