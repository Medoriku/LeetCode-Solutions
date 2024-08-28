class Solution {
public:
    bool isAnagram(string s, string t) {
        int counter = 0;

        if (s.length() != t.length()){
            return false;
        }

        for (int i = 0; i < s.length(); ++i){
            if (t.find(s[i]) != string::npos){
                counter += 1;
                t.erase(t.find(s[i]), 1);
                s.erase(i, 1);
                continue;
            }
            else if (t.find(s[i]) == string::npos){
                return false;
            }
        }
        cout << counter;
        return (s.length() == t.length());

    }
};