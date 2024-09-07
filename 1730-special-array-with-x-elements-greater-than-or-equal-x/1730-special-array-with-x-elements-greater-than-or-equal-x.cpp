class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        
        // Проверяем каждое возможное значение x от 0 до n
        for (int x = 0; x <= n; ++x) {
            int count = 0;
            for (int num : nums) {
                if (num >= x) {
                    count++;
                }
            }
            // Если количество чисел равно x, возвращаем x
            if (count == x) {
                return x;
            }
        }
        
        return -1;  // Если не нашли такого x, возвращаем -1
    }
};
