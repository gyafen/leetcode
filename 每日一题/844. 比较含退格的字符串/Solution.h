#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        cout << S << endl << T << endl;
        string ns;
        string nt;
        for (auto c : S)
        {
            if (c == '#')
            {
                if (!ns.empty())
                    ns.pop_back();
            }
            else
            {
                ns.push_back(c);
            }
        }
        for (auto c : T)
        {
            if (c == '#')
            {
                if (!nt.empty())
                    nt.pop_back();
            }
            else
            {
                nt.push_back(c);
            }
        }
        cout << ns << endl
             << nt;
        if (ns == nt)
        {
            return true;
        }
        return false;
    }
};
