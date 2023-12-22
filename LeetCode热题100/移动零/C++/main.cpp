#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};

    (new Solution())->moveZeroes(nums);
    return 0;
}


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int temp = 0;
        unsigned int posA = 0;  /*第一个〇的位置*/
        unsigned int posB = 0;  /*第一个〇之后，第一个非〇的位置*/
        while((posA<nums.size()) && (nums[posA]!=0)) posA++;

        posB = posA+1;

        while((posB<nums.size()) && (nums[posB]==0)) posB++;

        while (posB < nums.size())
        {
            if((nums[posA]==0) && (nums[posB]!=0)){
                nums[posA++] = nums[posB];
                nums[posB++] = 0;
            }
            while((posA<nums.size()) && (nums[posA]!=0)) posA++;
            while((posB<nums.size()) && (nums[posB]==0)) posB++;
        }
    }
};