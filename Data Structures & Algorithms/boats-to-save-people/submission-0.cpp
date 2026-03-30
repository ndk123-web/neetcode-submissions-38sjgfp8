class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0;
        int right = people.size() - 1;
        int res = 0;

        sort(people.begin(),people.end());

        while (left <= right) {
            int leftShouldBe = limit - people[right];
            right--;

            res++;

            if (left <= right && people[left] <= leftShouldBe) {
                left++;
            }
        }      

        return res;
    }
};