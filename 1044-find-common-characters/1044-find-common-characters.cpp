class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        multiset<char> initial_charset (words[0].begin(), words[0].end());

        for (int i = 1; i < words.size(); ++i){
            multiset<char> current_charset(words[i].begin(), words[i].end());
            multiset<char> common_charset;

            set_intersection(initial_charset.begin(), initial_charset.end(),
                current_charset.begin(), current_charset.end(),
                inserter(common_charset, common_charset.begin()));
        
        initial_charset = common_charset;
        }

        vector<string> result;
        for (char c : initial_charset) {
            result.push_back(std::string(1, c));
        }

    return result;
    }
};