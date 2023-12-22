#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
    return 0;
}

class Solution{
    public:
    int longestConsecutive(vector<int>& nums){
        int answer = 0;
        int count = 0;
        int next = 0;
        unordered_set<int> set;
        unordered_map<int, int> dealt;

        for(int num:nums) set.insert(num);

        for(int num:set){
            if(dealt.count(num-1)>0) dealt[num] = dealt[num-1]-1;
            else if(dealt.count(num+1)>0) dealt[num] = dealt[num+1]+1;
            else{
                count = 1;
                next = num+1;
                while (set.count(next))
                {
                    if(dealt.count(next)>0){
                        count+=dealt[next];
                        break;
                    }
                    count++;
                    next++;
                }
                dealt[num] = count;
            }
            answer = (answer>=dealt[num])?answer:dealt[num];
        }

        return answer;
    }
};