#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int                     long long int
#define ld                      long double
#define pb                      push_back
#define MOD                     1000000007
#define inf                     3e18
#define vi                      vector<int>
#define vld                     vector<ld>
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define fi                      first
#define se                      second
#define fastIO                  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << " "<< name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; 
		//order_of_key (k) : Number of items strictly smaller than k .
		//find_by_order(k) : K-th element in a set (counting from zero) (returns an iterator)           


void inp_out()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
	#endif
}


 // A  =  P(1+r / n) ^ nt
ld A, P;
int t, n;  
vector < ld > EMI; 

ld cal(ld r)
{
	ld res = P; 
	int init = P; 
	for(int i = 0; i < t; ++ i)
	{
		int x = ((init * r) / (ld)100); 
		res += x; 
		init -= (EMI[i] - x); 
	}

	return res;  
}

int32_t main()
{
	fastIO
	inp_out();


	cout << "Enter Principal Amount  : "; 
	cin >> P; 


	cout << "Enter time Period in Months : "; 
	cin >> t; 

	cout << "Enter number of different EMI : "; 
	cin >> n; 


	cout << "Enter EMIs and its time period in month : "; 

	for(int i = 0; i < n; ++ i)
	{
		int x, y; 
		cin >> x >> y; 
		for(int j = 0; j < y; ++ j)
			EMI.pb(x); 
	}

	assert(EMI.size() == t); 

	A  = accumulate(EMI.begin(), EMI.end(), (ld)0);  

	ld low = 0, high = 100; 
	int t = 100; 

	ld ans; 

	while(t-- )
	{
		ld mid = (low + high) / 2; 

		if(cal(mid) > A)
		{
			ans = mid; 
			high = mid; 
		}
		else low = mid; 
	}

	cout << "\nReducing Rate of Interest Per Annum is : " << fixed << setprecision(2) << (ans * (ld)12); 
	

	return 0;
}

