class Solution {
public:
	int romanToInt(string s) {
		int integer = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];

			if (c == 'M'){
				if (i > 0)
				{
					if (s[i - 1] == 'C')
					{
						//integer = integer - 100;
						integer = integer + 800;
					}
					else
					{
						integer = integer + 1000;
					}
				}
				else
				{
					integer = integer + 1000;
				}
			}
			else if (c == 'D'){
				if (i > 0)
				{
					if (s[i - 1] == 'C')
					{
						//integer = integer - 100;
						integer = integer + 300;
					}
					else
					{
						integer = integer + 500;
					}
				}
				else
				{
					integer = integer + 500;
				}
			}
			else if (c == 'C'){
				if (i > 0)
				{
					if (s[i - 1] == 'X')
					{
						//integer = integer - 100;
						integer = integer + 80;
					}
					else
					{
						integer = integer + 100;
					}
				}
				else
				{
					integer = integer + 100;
				}
			}
			else if (c == 'L'){
				if (i > 0)
				{
					if (s[i - 1] == 'X')
					{
						//integer = integer - 100;
						integer = integer + 30;
					}
					else
					{
						integer = integer + 50;
					}
				}
				else
				{
					integer = integer + 50;
				}
			}
			else if (c == 'X'){
				if (i > 0)
				{
					if (s[i - 1] == 'I')
					{
						//integer = integer - 100;
						integer = integer + 8;
					}
					else
					{
						integer = integer + 10;
					}
				}
				else
				{
					integer = integer + 10;
				}
			}
			else if (c == 'V'){
				if (i > 0)
				{
					if (s[i - 1] == 'I')
					{
						//integer = integer - 100;
						integer = integer + 3;
					}
					else
					{
						integer = integer + 5;
					}
				}
				else
				{
					integer = integer + 5;
				}
			}
			else if (c == 'I'){
				integer += 1;
			}
		}
		return integer;
	}
};
