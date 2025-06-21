/*
Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3]
Output: 5
*/
class Solution {
  public:
    int findUnion(vector<int>& a, vector<int>& b) {
        int a_length = a.size();
        int b_length = b.size();
        if (a_length == 0 && b_length == 0) {
            return 0;
        }
        std::set<int> result;
        for (int i = 0; i < a_length; i++) {
            result.insert(a[i]);
        }
        for (int i = 0; i < b_length; i++) {
            result.insert(b[i]);
        }
        return result.size();
    }
};