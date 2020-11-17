class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		multimap<int, vector<int>> cellOrder;
		vector<vector<int>> rslt;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				int d;
				d = abs(i - r0) + abs(j - c0);
				cellOrder.insert(pair<int, vector<int>>(d, { i, j }));
			}
		}
		for (auto cell : cellOrder)
		{
			rslt.push_back(cell.second);
		}

		return rslt;
	}
};
