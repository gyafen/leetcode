class Solution {
    public void moveZeroes(int[] nums) {
        int zerop = 0;
        int nzerop = 0;
        int length = nums.length;

        //第一个0的位置
        while (zerop<length && nums[zerop] != 0){
            zerop++;
        }
        nzerop = zerop+1;
        //第一个0后面第一个非0位置
        while (nzerop < length && nums[nzerop] == 0){
            nzerop++;
        }

        while (nzerop < length){
            //交换
            int tmp = nums[nzerop];
            nums[nzerop] = nums[zerop];
            nums[zerop] = tmp;


            //下一个0
            while (zerop < length && nums[zerop] != 0){
                zerop++;
            }
            //下一个非0
            while (nzerop < length && nums[nzerop] == 0){
                nzerop++;
            }
        }

        // 4 0 1 5 2 0
        // 4 1 5 2 0 0
    }
}
