class Solution {
private:
    void backtrack (string curr, int countOpen, int countClose, int givenSize, vector<string> &res){
        if (countOpen == givenSize && countClose == givenSize) {
            res.push_back(curr);
            return;
        }
        if (countOpen < givenSize)
            backtrack(curr + '(', countOpen + 1, countClose, givenSize, res);
        if (countClose < countOpen)
            backtrack(curr + ')', countOpen, countClose + 1, givenSize, res);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", 0, 0, n, res);
        return res;
    }
};