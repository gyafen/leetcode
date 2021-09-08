class Solution {
    public void moveZeroes(int[] nums) {
        int zerop = 0;
        int nzerop = 0;
        int length = nums.length;

        while (zerop<length && nums[zerop] != 0){
            zerop++;
        }
        nzerop = zerop+1;
        while (nzerop < length && nums[nzerop] == 0){
            nzerop++;
        }

        while (nzerop < length){
            int tmp = nums[nzerop];
            nums[nzerop] = nums[zerop];
            nums[zerop] = tmp;

            while (zerop < length && nums[zerop] != 0){
                zerop++;
            }
            while (nzerop < length && nums[nzerop] == 0){
                nzerop++;
            }
        }

        // 4 0 1 5 2 0
        // 4 1 5 2 0 0
    }
}
