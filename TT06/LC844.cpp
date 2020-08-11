class Solution {
public:
    int sub(string &S) {
        int n = S.length();
        int i = 0, j = 0;
        while(j < n) {
            if(S[j] != '#') S[i++] = S[j++];
            else {
                j++;
                if(i > 0) i--;
            }
            // printf("i=%d %c j=%d %c\n", i, S[i], j, S[j]);
        }
        // cout << S << endl;
        return i;
    }
    bool backspaceCompare(string S, string T) {
        int a = sub(S);
        int b = sub(T);
        if(a != b) return false;
        for(int i = 0;i < a;i++) if(S[i] != T[i]) return false;
        return true;
    }
};