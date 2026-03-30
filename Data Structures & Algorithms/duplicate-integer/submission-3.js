class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        let mapp = {};
        for (let i=0 ; i<nums.length ; i++){
            mapp[nums[i]] = (mapp[nums[i]] || 0 ) + 1  
            if (mapp[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
}
