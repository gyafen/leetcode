#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int getFirstNumberNotLessThanZero(const vector<int>& A){
        int ret = A.size() - 1;
        for(int i = 0; i < A.size(); i++){
            if(A[i] >= 0){
                ret = i;
                break;
            }
        }
        return ret;
    }

    vector<int> sortedSquares(vector<int>& A){
        vector<int> squareA;
        int mid = getFirstNumberNotLessThanZero(A);
        int left = mid-1;
        int right = mid;
        while(left >= 0 && right < A.size()){
            if(pow(A[left], 2) < pow(A[right], 2)){
                squareA.push_back(pow(A[left--], 2));
            }
            else{
                squareA.push_back(pow(A[right++], 2));
            }
        }
        while (left >= 0){
                squareA.push_back(pow(A[left--], 2));
        }
        while (right < A.size()){
            squareA.push_back(pow(A[right++], 2));
        }
        
        return squareA;
        
    }

};

