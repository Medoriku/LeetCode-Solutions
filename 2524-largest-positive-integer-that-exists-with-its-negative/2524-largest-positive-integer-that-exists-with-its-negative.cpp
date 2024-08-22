class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxInt = 0;
        vector<int> potentials;
        
        for (int i = 0; i<nums.size(); ++i){
            auto it = find(nums.begin(), nums.end(), (-(nums[i])));
            if ((nums[i]>maxInt) && (it!= nums.end())){
                potentials.push_back(i);
                maxInt = nums[i];
            }
        }

        if (potentials.size() == 0){
            return -1;
        }
        return maxInt;
    }
};