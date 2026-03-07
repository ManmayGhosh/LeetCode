class Solution {
public:
    int minFlips(string s) {
        if(s.size()<2)
            return 0;
        int n = s.size();
        s += s;
        int ans = INT_MAX;
        int d = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != ((i%2)?'1':'0')) 
                d++;
            if(i>=n && s[i-n]!=(((i-n)%2)?'1':'0'))
                d--;
            if(i>=n-1)
                ans=min(ans,min(d,n-d));
        }
        return ans;
    }
};