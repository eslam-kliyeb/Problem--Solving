#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl "\n"
#define pi 3.141592653589793
#define ll long long
#define ld long double
#define pb(x) push_back(x);
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define fixed      \
    cout << fixed; \
    cout.precision(9)
#define sza(r) ((int)r.size())
#define all(u) (u).begin(), (u).end()
#define ign cin.ignore(numeric_limits<std::streamsize>::max(), '\n')
#define home string::npos
#define ma_mod(a, n) ((a % n) + n) % n
#define cl(x, y) ((x + y - 1) / y)
#define ON(n, k) ((n) | (1 << k))
#define OFF(n, k) ((n) & (~(1 << k)))
#define isON(n, k) (((n) >> (k)) & 1)
using namespace std;
using namespace std::chrono;
void File()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}
#ifndef ONLINE_JUDGE
#include "QueenEman - Copy.h"
#define debug(x...)      \
    cerr << #x << " = "; \
    __print(x);          \
    cout << endl;
#else
#define debug(x...)
#endif
//============================================================
int di[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dj[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
//============================================================
const int SZ = (1e5 + 3);
const ll CON = (1e18);
const ll inf = (1 << 30);
const int MOD = (1e9 + 7);
const int M = (3005);
//============================================================
//============================================================
// 1 sec = 10^8 operations
//============================================================
int n;
//============================================================
void testcace()
{
     deque<int>dq;
     for(int i=1;i<=n;i++){
         dq.push_back(i);
     }
     //============================
     if(dq.size()==1){
         cout << "Discarded cards:" << endl;
         cout << "Remaining card: " << dq.back() << endl;
         return;
     }
     //============================
     cout << "Discarded cards: ";
    while (dq.size()!=2){
        cout << dq.front() << ", ";
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout << dq.front() << endl;
    cout << "Remaining card: " << dq.back() << endl;
}
//=============================================================
int main()
{
    fast;
    fixed;
    File();
    //=================================================================
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //=================================================================
    //int t = 1;
    //cin >> t;
    while (cin >> n , n)
    {
        testcace();
    }
    //=================================================================
    return 0;
}