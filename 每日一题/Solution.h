class Solution {
public:
	int canCompleteCircuit(vector<int> gas, vector<int> cost) {
		vector<int> canpst;
		int size = gas.size();
		for (int i = 0; i < size; i++)
		{
			if (gas[i] >= cost[i])
			{
				canpst.push_back(i);
			}
		}

		for (auto i : canpst)
		{
			int rest = 0;
			int can = 1;

			for (int j = 0; j < size; j++)
			{
				if (rest + gas[(i + j)%size] >= cost[(i + j)%size])
				{
					rest = rest + gas[(i + j)%size] - cost[(i + j)%size];
				}
				else
				{
					can = 0;
					break;
				}
			}
			if (can == 1)
			{
				return i;
			}
		}
		return -1;
	}
};
