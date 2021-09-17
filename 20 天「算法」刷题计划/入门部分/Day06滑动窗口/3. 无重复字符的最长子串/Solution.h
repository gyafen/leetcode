class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int longest = -1;
        unordered_set<char> windows;
        bool repeat = false;
        char repeatChar = '#';

        if(s.length() == 1){
            return 1;
        }

        while (right < s.length()) {
            if (windows.count(s[right]) > 0) {
                repeat = true;
                repeatChar = s[right];
                break;
            }
            windows.insert(s[right++]);
        }

        if (!repeat) {
            return s.length();
        }

        if (right - left > longest) {
            longest = right - left;
        }

        while (right < s.length()) {
            while (repeat && left < right) {
                windows.erase(s[left]);
                if (s[left] == repeatChar) {
                    repeat = false;
                }
                left++;
            }

            while (right < s.length()) {
                if (windows.count(s[right]) > 0) {
                    repeat = true;
                    repeatChar = s[right];
                    break;
                }
                windows.insert(s[right++]);
            }
            if (right - left > longest) {
                longest = right - left;
            }
        }
        return longest;
    }
};
