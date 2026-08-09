class Solution {
public:
std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        // Store pairs of {value, original_index}
        std::vector<std::pair<int, int>> num_with_index(n);
        for (int i = 0; i < n; i++) {
            num_with_index[i] = {nums[i], i};
        }

        // Sort by value (std::pair sorts by the first element by default)
        std::sort(num_with_index.begin(), num_with_index.end());

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int currentSum = num_with_index[left].first + num_with_index[right].first;

            if (currentSum == target) {
                // Return original indices
                return {num_with_index[left].second, num_with_index[right].second};
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};