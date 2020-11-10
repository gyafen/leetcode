class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size >= 2){
          int beginInvertPst = 0;
          int tailMaximal = nums.back();
          for(int i = size-2; i >= 0; i--){
            if(nums[i] < tailMaximal){
              // i 位置的数小于 i 后面出现的最大的数
              // 因此 i 要和 i 后面大于 nums[i] 的最小数交换
              // 由于 i 后面的数是降序排列的
              // 因此可以从末尾再走一遍，找到第一个比 nums[i]大的数交换
              for(int j = size-1; j > i; j--){
                if(nums[j] > nums[i]){
                  swap(nums[j], nums[i]);
                  break;
                }
              }
              beginInvertPst = i+1;
              break;
            }
            tailMaximal = nums[i];
          }

          int swapTimes = (size - beginInvertPst)/2;
          for(int i = 0; i < swapTimes; i++)
          {
            swap(nums[beginInvertPst+i], nums[size-1-i]);
          }
        }
    }
};
