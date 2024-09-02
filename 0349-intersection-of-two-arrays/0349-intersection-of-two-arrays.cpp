class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> result;
        for (int i = 0; i < nums2.size(); ++i){
            auto it_nums1 = find(nums1.begin(), nums1.end(), nums2[i]);
            auto it_result = find(result.begin(), result.end(), nums2[i]);

            if (it_nums1 != nums1.end() && it_result == result.end()){
                result.push_back(nums2[i]);
            }
            else {
                continue;
            }
        }
        return result;
    }
};