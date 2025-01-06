class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        // Left to right pass
        int operations = 0, balls = 0;
        for (int i = 0; i < n; ++i) {
            answer[i] += operations;
            balls += (boxes[i] == '1');
            operations += balls;
        }

        // Right to left pass
        operations = 0;
        balls = 0;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += operations;
            balls += (boxes[i] == '1');
            operations += balls;
        }

        return answer;
    }
};
