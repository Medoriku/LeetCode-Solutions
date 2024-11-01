class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // Calculate the area with the current left and right lines
            int area = min(height[left], height[right]) * (right - left);
            // Update max_area if this area is larger
            max_area = max(max_area, area);
            
            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
