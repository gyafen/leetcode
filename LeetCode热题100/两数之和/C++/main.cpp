#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

    return 0;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++){
            map.insert(pair<int, int>(nums[i], i));
        }
        for(int i = 0; i < nums.size(); i++){
            if(map.count(target-nums[i]) > 0 && i != map[target-nums[i]]){
                answer.push_back(i);
                answer.push_back(map[target-nums[i]]);
                break;
            }
        }
        return answer;
    }
};