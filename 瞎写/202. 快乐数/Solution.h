class Solution {
public:
	bool isHappy(int n) {
		set<int> rcd;

		while (n != 1)
		{
			if (rcd.count(n) == 0)
			{
				rcd.insert(n);
				int squareSum = 0;
				while (n != 0)
				{
					int e = n % 10;
					n = n / 10;
					squareSum += pow(e, 2);
				}
				n = squareSum;
			}
			else
			{
				cout << n;
				return false;
			}


		}
		return true;
	}
};
