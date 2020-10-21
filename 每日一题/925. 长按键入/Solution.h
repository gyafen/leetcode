#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int suo = 0;
		char last;
		int i = 0;
		int j = 0;
		for (; (i<name.length()) && (j<typed.length()); i++)
		{
			if (0 == suo)
			{
				suo = 1;
				if (name[i] == typed[j])
				{
					last = typed[j];
					j++;
				}
				else
				{
					return false;
				}

			}
			else
			{
				if (name[i] != typed[j])
				{
					while (last == typed[j])
					{
						j++;
					}
					if (name[i] != typed[j])
					{
						return false;
					}
					else
					{
						last = typed[j];
						j++;
					}

				}
				else
				{
					last = typed[j];
					j++;
				}
			}
			cout << last << endl;
		}
		if (i<name.length())
		{
			return false;
		}
		for (; j<typed.length(); j++)
		{
			if (typed[j] != last)
			{
				return false;
			}
		}
		return true;
	}
};

//alex      aaaleex
