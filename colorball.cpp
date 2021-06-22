#include <iostream>
#include <algorithm>
using namespace std;
const int MN = 200000 + 1;
int N, accul, colorSum[MN], ret[MN];
struct Ball { int c, s, idx; } ball[MN];
bool COMP(const Ball &a, const Ball &b) { return a.s < b.s; }
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &ball[i].c, &ball[i].s); ball[i].idx = i;
    }
    sort(ball, ball + N, COMP);
    for (int i = 0, j = 0; i < N; ++i){
        for (; ball[i].s > ball[j].s; ++j) {
            accul += ball[j].s;
            colorSum[ball[j].c] += ball[j].s;
        }
        ret[ball[i].idx] = accul - colorSum[ball[i].c];
    }
    for (int i = 0; i < N; ++i) printf("%d\n", ret[i]);
    return 0;
}
