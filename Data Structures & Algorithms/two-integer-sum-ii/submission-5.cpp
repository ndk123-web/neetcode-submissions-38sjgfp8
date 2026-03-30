class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> res(2,0);
        int sum = 0;

        while (left < right) {
            sum = numbers[left] + numbers[right];

            if (sum == target) {
                res[0] = left + 1;
                res[1] = right + 1;
                break;
            }

            else if (sum < target) {
                sum = sum - numbers[left];
                left++;
            }
            else {
                sum = sum - numbers[right];
                right--;
            }
        }

        return res;
       
    }
};
