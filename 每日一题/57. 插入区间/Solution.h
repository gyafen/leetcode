#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

		vector<vector<int>> rslt;

		if (intervals.size() < 1)
		{
			rslt.push_back(newInterval);
			return rslt;
		}

		int index = 0;
		int status = 1;
		for (; index < intervals.size(); index++)
		{
			vector<int> interval = intervals[index];
			//一共有五中可能性：
			
			//第一种，新区间完全在当前区间的左侧
			//           | [        ]
			//           |
			//[        ] |
			//将新区间插入到当前区间前面即可
			if (newInterval[1] < interval[0])
			{
				rslt.push_back(newInterval);
				rslt.push_back(interval);
				status = 0;
				break;
			}

			/*第二种,新区间的右侧和当前区间的左侧有部分交集

				  [ |       ]
			        |
			 [      |  ]

			 将这两个区间合并，插入到rslt中
			*/
			else if (newInterval[0] <= interval[0] && interval[0] <= newInterval[1] && interval[1] >= newInterval[1])
			{
				vector<int> cb;
				cb.push_back(newInterval[0]);
				cb.push_back(interval[1]);
				rslt.push_back(cb);
				status = 0;
				break;
			}

			/*第三种，新区间被当前区间完全包含
			
				  [      |       ]
			             |
			          [  |  ]
			
			  直接将interval插入rslt即可
			*/
			else if (newInterval[0] >= interval[0] && newInterval[1] <= interval[1])
			{
				rslt.push_back(interval);
				status = 0;
				break;
			}


			/*第四种

				[  |  ]
				   |
			 [     |     ]

			啥都不用做
			*/
			else if (interval[0] >= newInterval[0] && interval[1] <= newInterval[1])
			{

			}

			/*第五种

			[      |  ]
				   |
			    [  |       ]

			合并两者，作为新的newInterval
			*/
			else if (interval[0] <= newInterval[0] && newInterval[0] <= interval[1] && newInterval[1] >= interval[1])
			{
				vector<int> cb;
				cb.push_back(interval[0]);
				cb.push_back(newInterval[1]);
				newInterval = cb;
			}

			/*第六种

			[        ]  |
						|
						| [         ]

			将interval push 到 rslt 中
			*/
			else if (interval[1] < newInterval[0])
			{
				rslt.push_back(interval);
			}
		}


		if (index < intervals.size())
		{
			for (index = index + 1; index < intervals.size(); index++)
			{
				rslt.push_back(intervals[index]);
			}
		}

		if (status == 1)
		{
			rslt.push_back(newInterval);
		}

		return rslt;
	}
};
