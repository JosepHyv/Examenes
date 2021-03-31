#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

typedef long long int ll;


int main()
{
	ifstream valfin("data.out",ifstream::in);
	ll n = 0 ;
	valfin >> n;
	vector < string> pc;
	for(int c = 0 ; c<n; c++)
	{
		string a;
		valfin>>a;
		pc.push_back(a);
	}
	ll ans_consursante = 0 ;
	cin>>ans_consursante;
	vector<string> v2;
	for(int c = 0 ; c<ans_consursante; c++)
	{
		string b;
		cin>>b;
		v2.push_back(b);

	}
	

	if( !ans_consursante || (int)v2.size() == 0 )
	{
		cout<<"El competidor no dio salida\n";
		cout<<0.0<<"\n";
		return 0;
	}

	if( ans_consursante > n)
	{
		cout<<"Hay una solucion más corta\n";
		cout<<0.0<<"\n";
		return 0;
	}

	if( ans_consursante < n)
	{
		cout<<"Eso no es posible\n";
		cout<<0.0<<"\n";
		return 0;
	}

	int tam = v2.size();
	if( tam != n)
	{
		cout<<"No corresponden las salidas\n";
		cout<<0.0<<"\n";
		return 0;
	}
	

	cout<<1.0<<"\n";
	return 0;
	
}