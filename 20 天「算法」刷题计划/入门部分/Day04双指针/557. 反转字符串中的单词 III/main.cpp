    int first = true;
    bool foundNextPos(string &s, int &left, int &right){
        if(first == true){
            while (right < s.size() && s[right] != ' '){
                right++;
            }
            right--;
            return true;
        }
        
        
        
        //left
        //先把当前单词走完
        while (left < s.size() && s[left] != ' '){
            left++;
        }
        //当前单词是末尾
        if(left == s.size()){
            return false;
        }

        while (left < s.size() && s[left] == ' '){
            left++;
        }

        //语句以空格结束
        if(left == s.size()){
            return false;
        }

        right = left;

        while (right < s.size() && s[right] != ' '){
            right++;
        }
        right--;
        
        return true;
    }


    string reverseWords(string s) {
        int left = 0;
        int right = 0;

        while (foundNextPos(s, left, right)){
            while(left < right){
                auto tmp = s[left];
                s[left++] = s[right];
                s[right--] = tmp;
            }
            first = false;
        }


    }
