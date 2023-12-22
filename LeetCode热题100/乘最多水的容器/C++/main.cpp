#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    int maxArea(vector<int>& height){
        int left = 0;
        int right = height.size()-1;
        int answer = 0;
        int cArea = 0;

        while (left<right)
        {
            cArea = (right-left)*(height[left]<height[right]?height[left]:height[right]);
            answer = (answer>cArea?answer:cArea);
            if(height[left]<height[right]) left++;
            else right--;
        }
        return answer;
    }
};