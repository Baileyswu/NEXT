#include <bits/stdc++.h>
using namespace std;
const int N = 5e4+10;

int n, m, tot;
map<int, pair<int, int>> id2p;
map<pair<int, int>, int> p2id;

struct UF
{
    int p[N<<2];
    void init() {
        memset(p, -1, sizeof(p));
    }
    int find(int x) {
        if(p[x] == -1 || p[x] == x)
            return x;
        return p[x] = find(p[x]);
    } 
    int join(int x, int y) {
        int px = find(x);
        int py = find(y);
        return p[px] = py; // p[px] = p[py] is wrong util p[x] = x as initialization
    }
}ww, ee, nn, ss;

int insert(int x, int y) {
    if(p2id.count(make_pair(x, y)))
        return p2id[make_pair(x, y)];
    // printf("insert (%d, %d) id=%d\n", x, y, tot);
    id2p[tot] = make_pair(x, y);
    p2id[make_pair(x, y)] = tot;
    return tot++;
}

void update(int id) {
    int gd;
    auto p = id2p[id];
    int x = p.first;
    int y = p.second;
    gd = insert(x, y-1);
    ww.join(id, gd);
    gd = insert(x, y+1);
    ee.join(id, gd);
    gd = insert(x-1, y);
    nn.join(id, gd);
    gd = insert(x+1, y);
    ss.join(id, gd);
}

void init() {
    tot = 0;
    id2p.clear();
    p2id.clear();
    ww.init();
    ee.init();
    nn.init();
    ss.init();
}

void go(int &x, int &y, char c) {
    // printf("---- go from (%d, %d) %c \n", x, y, c);
    int id = insert(x, y);
    int gd;
    update(id);
    switch (c)
    {
    case 'W':
        id = ww.find(id);
        break;
    case 'E':
        id = ee.find(id);
        break;
    case 'N':
        id = nn.find(id);
        break;
    case 'S':
        id = ss.find(id);
        break;
    default:
        break;
    }
    auto p = id2p[id];
    x = p.first;
    y = p.second;
}

int main() {
    int T, o = 0;
    cin >> T;
    while(T--) {
        string s;
        int l, x, y;
        init();
        cin >> l >> n >> m >> x >> y >> s;
        for(int i = 0;i < l;i++) {
            go(x, y, s[i]);
        }
        printf("Case #%d: %d %d\n", ++o, x, y);
    }
    return 0;
}