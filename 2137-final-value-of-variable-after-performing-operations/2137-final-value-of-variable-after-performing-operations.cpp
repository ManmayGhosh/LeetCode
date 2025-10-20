class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
    int X = 0;
	for (string str : operations) {
		if (str == "--X" || str == "X--")
		{
			X--;
		}
		else
		{
			X++;
		}
	}
	return X;
    }
};