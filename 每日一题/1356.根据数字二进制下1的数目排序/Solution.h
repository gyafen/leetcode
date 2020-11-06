#include <iostream>
#include <vector>
#include <set>
#include <hash_map>
#include <bitset>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> sortByBits(vector<int>& arr) {
		vector<int> rst;
		int pst = 0;
		for (int oneCount = 0; oneCount < 14; oneCount++)
		{
			//vector<int> oneCountLevel;
			int start = pst;
			for (auto num : arr)
			{
				bitset<14> bInt = bitset<14>(num);
				if (bInt.count() == oneCount)
				{
					rst.push_back(num);
					pst++;
				}
			}
			sort(rst.begin()+start, rst.begin()+pst);

		}
		return rst;
	}
};
