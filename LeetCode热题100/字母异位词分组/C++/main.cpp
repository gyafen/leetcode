#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){

    return 0;
}

class Solution {
public:
    string  sort_string(string s){
        char* data;
        string sorted_s;

        data = s.data();
        sort(data, data+s.size());
        sorted_s = data;
        return sorted_s;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> map;
        
        for(string s:strs)  map[sort_string(s)].push_back(s);
        for(auto pair:map)  answer.push_back(pair.second);

        return answer;
    }
};