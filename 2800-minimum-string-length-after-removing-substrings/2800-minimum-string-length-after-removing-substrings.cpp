class Solution {
public:
    int minLength(string s) {
        std::stack<char> st;
        
        for (char c : s) {
            if (!st.empty() && 
               ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D'))) {
                st.pop(); // Remove the previous character forming AB or CD
            } else {
                st.push(c); // Push the current character onto the stack
            }
        }
        
        return st.size(); // The size of the stack is the minimized length
    }
};
