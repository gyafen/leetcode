#include <vector>

using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int sum = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					//向上
					if (i == 0)
					{
						++sum;
					}
					else
					{
						if (grid[i - 1][j] == 0)
						{
							++sum;
						}
					}

					//向右
					if (j == grid[i].size() - 1)
					{
						++sum;
					}
					else
					{
						if (grid[i][j + 1] == 0)
						{
							++sum;
						}
					}

					//向下
					if (i == grid.size() - 1)
					{
						++sum;
					}
					else
					{
						if (grid[i+1][j] == 0)
						{
							++sum;
						}
					}

					//向左
					if (j == 0)
					{
						++sum;
					}
					else
					{
						if (grid[i][j - 1] == 0)
						{
							++sum;
						}
					}
				}
			}
		}
		return sum;
	}
};
