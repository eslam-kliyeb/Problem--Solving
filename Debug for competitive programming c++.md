# Debug for competitive programming c++



---

---

## How use ?!

- You must take the code shown below and put it in your programming space,
and the tasks must be executed after the place where the code was placed in order for it to work correctly,
and then you must create a file named `Error.txt` so that 
the debuge result appears in it, and then call `Debug` function in the `main` function so that the result appears with you in 
the file that you created

- Type the word `debug (the name of the thing you want to show inside)`

---

## Stuff available to correct it 

- `pair <T, V> p`
- `vector <T> v`
- `vector<pair <T,V>> v`
- `vector<vector<T>> v`
- `vector<pair <T,pair<V,H>>> v`
- `set <T> v)`
- `map <T, V> v`
- `map <T, vector<V>> v`
- `multiset <T> v`
- `unordered_map <T, vector<V>> v`
- `deque<T> v`
- `queue<T> v`
- `priority_queue<T> v`
- `stack<T> v`

---

### code debug :

```c++
void Debug()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
}
//================================================================
//-------------------------Debug---------------------------------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
//----------------------------------------------------------------
void _print(double t) {cerr << t;}
void _print(long long t)     {cerr << t;}
void _print(int t)    {cerr << t;}
void _print(float t)  {cerr << t;}
void _print(bool t)   {cerr << t;}
void _print(long double t)    {cerr << t;}
void _print(unsigned long long t)    {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t)   {cerr << t;}
//------------------------------------to make it visible to other _print---------------------------------------------------------
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T, class V> void _print(vector<pair <T,V>> v);
template <class T> void _print(vector<vector<T>> v);
template <class T, class V , class H> void _print(vector<pair <T,pair<V,H>>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(map <T, vector<V>> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(unordered_map <T, vector<V>> v);
template <class T> void _print(deque<T> v);
template <class T> void _print(queue<T> v);
template <class T> void _print(priority_queue<T> v);
template <class T> void _print(stack<T> v);
//---------------------------------------------------------------------------------------------------------------------------
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector<vector<T>> v) {cerr << "[ "; for (auto i : v) {cerr << endl;_print(i);cerr << ",";} cerr << "]";}
template <class T, class V> void _print(vector<pair <T,V>> v) {cerr << "[ "; for (auto i : v) {cerr << endl;_print(i);} cerr << "]";}
template <class T, class V , class H> void _print(vector<pair <T,pair<V,H>>> v) {cerr << "[ "; for (auto i : v) {cerr << endl;_print(i);} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]" << endl;}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, vector<V>> v) {cerr << "[ \n"; for (auto i : v) {cerr << endl;_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, vector<V>> v) {cerr << "[ \n"; for (auto i : v) {cerr << endl;_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(deque<T> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(queue<T> v) {cerr << "[ "; while (!v.empty()) {_print(v.front()); v.pop(); cerr << " ";} cerr << "]";}
template <class T> void _print(priority_queue<T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); v.pop(); cerr << " ";} cerr << "]";}
template <class T> void _print(stack<T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); v.pop(); cerr << " ";} cerr << "]";}
```

---
