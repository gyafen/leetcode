class Solution {
public:
	bool validMountainArray(vector<int>& A) {

		if (A.size() < 3)
		{
			return false;
		}

		int state = 1;

		int pre = 0;
		int suo = 0;
		int length = 0;
		for (auto a : A)
		{
			if (suo == 0)
			{
				pre = a;
				suo = 1;
			}
			else
			{
				if (state == 1 && a > pre)
				{
					length++;
					pre = a;
					continue;
				}
				else
				{
					if (state == 1 && a < pre)
					{
						if (length < 2)
						{
							return false;
						}
						state = 0;
					}
					if (state == 0 && a >= pre)
					{
						return false;
					}
				}
				pre = a;
			}
			length++;
		}
		if (state == 1)
		{
			return false;
		}
		return true;
	}
};
