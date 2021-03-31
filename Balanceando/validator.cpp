#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

typedef long long int ll;
constexpr int MAXM = 1e6+2;


int cuenta[MAXM];
int n,m;

int main()
{
	// leo la entrada original
	ifstream valin("data.in",ifstream::in);
	valin >> n >> m;
	int t = n / m;

	ifstream casein ("data.out",ifstream::in);
	int number = 0 ;
	casein >> number;
	/// busco que los pasos sean minimos;

	/// concursante
	int sol = 0;
	cin >> sol;
	for(int c = 0 ; c<n; c++)
	{
		int x;
		cin>>x;
		cuenta[x%m]++;
	}

/// debug
	/*for(int c = 0 ; c<m; c++)
		cerr<<c<<" "<<cuenta[c]<<"\n";*/
/// debug

	/// veredicto
	/// evaluando el numero de pasos
	if( !sol)
	{
		cerr<<"El concursante no dio salida\n";
		cout<<0.0<<"\n";
		return 0;
	}

	if( sol != number)
	{
		cerr<<"Hay una solucion mejor\n";
		cout<<0.0<<"\n";
		return 0;
	}

	/// evaluando el arreglo 
	for(int c = 0; c<m; c++)
		if( cuenta[c] != t)
		{
			cerr<<"El arreglo no es valido\n";
			cout<<0.0<<"\n";
			return 0;
		}

	cerr<<"Salida Valida\n";
	cout<<1.0<<"\n";
	return 0;


}
