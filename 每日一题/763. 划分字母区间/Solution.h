class Solution {
public:
    vector<int> partitionLabels(string S) {
        int ll[26];
        int length = S.size();
        for (int i = 0; i < length; i++) {
            ll[S[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, ll[S[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};
