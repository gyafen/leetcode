#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		vector<int> itsct;
		itsct.resize(min(nums1.size(), nums2.size()));

		vector<int>::iterator itsctEnd = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), itsct.begin());

		vector<int> rslt;
		int last = 6686465;
		for (vector<int>::iterator it = itsct.begin(); it != itsctEnd; it++)
		{
			if (*it != last)
			{
				rslt.push_back(*it);
				last = *it;
			}
		}
		

		return rslt;
	}
};
