#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define clr(x) memset( x, 0, sizeof(x))
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;

typedef long long int ll;
constexpr int maxn = 1e6;

void input(string a, int lim)
{
	fstream casos;
	casos.open(a.c_str(), ios::out);
	int n,t;

	n = (rand() % lim)+1;
	t = (rand() % lim) +1;
	while( true)
	{
		if( n % t == 0  && t != n && t > 1 )
			break;
		t = (rand() % lim) +1;
	}
	
	casos<<n<<" "<<t<<"\n";
	for(int c = 0 ; c<n; c++)
		casos<<(rand()%lim)+1<<" ";


	casos.close();
}

void output(string a)
{
	string b = a;
	b[sz(b)-2] = 'o';
	b[sz(b)-1] = 'u';
	b += 't';

	ifstream fin ( a.c_str());
	fstream casos;
	casos.open(b.c_str(), ios::out);

	///--- solution --///
	int n,m;
	ll ans = 0 ;
			fin>>n>>m;
			vector < ll > vx(n);
			vector < vector < int > > ss(m);
			for( int c = 0 ; c<n; c++)
			{
				fin>>vx[c];
				ss[vx[c] % m].pb(c);
			}
	 
			stack< pair < int , int > > trick;
			for( int c = 0; c<2*m; c++)
			{
				int actual = c % m;
				int tt = n / m;
				while( sz(ss[actual]) > tt)
				{
					int elm = ss[actual].back();
					ss[actual].pop_back();
					trick.push({elm, actual});
				}
				while( sz(ss[actual]) < tt && sz(trick))
				{
					int pos = trick.top().fi;
					ss[actual].pb(pos);
					vx[pos] += c - trick.top().se;
					ans += c - trick.top().se;
					trick.pop();
				}
			}
			casos<<ans<<"\n";
			for( auto a: vx)
				casos<<a<<" ";
			casos<<"\n";

}


int main () 
{

	srand( time( NULL ));
	int c = 11;
	for(; c<= 15; c++)
	{
		string pp = "balancea";
		pp += to_string(c);
		pp += ".in";
		input(pp,(int)1e5);
		output(pp);

	}
}
