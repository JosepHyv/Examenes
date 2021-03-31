#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define clr(x) memset( x, 0, sizeof(x))
using namespace std;

typedef long long int ll;
constexpr int maxn = 1e6;

void input(string a, int lim)
{
	fstream casos;
	casos.open(a.c_str(), ios::out);
	int n,m;
	n = (rand() % lim) +1 ;
	m = (rand() % lim) +1 ;
	casos<<n<<"\n";
	for(int c = 0; c<n; c++)
		casos<<(rand() % 1000)+1<<" ";
	casos<<"\n"<<m<<"\n";
	for(int c = 0 ; c<m; c++)
		casos<<(rand() % 1000)+1<<" ";
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
	int n,m;
	long long int parejas  = 0 ;
	 fin>>n;
	 vector < int > nvec(n);
    for(int c=0; c<n; c++)
        fin>>nvec[c];
    fin>>m;
    vector < int > mvec(m);
    for(int d=0;d<m;d++)
        fin>>mvec[d];
    sort(nvec.begin(),nvec.end());
    sort(mvec.begin(),mvec.end());
    for(int f=0,g=0; f<n && g<m;)
    {
        if(abs(mvec[g]-nvec[f])<2)
        {
            parejas++;
            f++;
            g++;
        }
        else
            {
                if(nvec[f]<mvec[g])
                    f++;
                else
                    g++;
            }
    }
    casos<<parejas;

	///--- solution --///

}


int main () 
{

	srand( time( NULL ));
	int c = 30;
	for(; ~c; c--)
	{
		string pp = "caso";
		pp += to_string(c);
		pp += ".in";
		input(pp,(int)1e5);
		output(pp);

	}
}
