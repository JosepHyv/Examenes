#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int ninos[100002];
int ninas[100002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for(int c = 0 ; c<n; c++)
		cin>>ninos[c];
	
	cin>>m;
	for(int c = 0 ; c<m; c++)
		cin>>ninas[c];

	sort(ninos, ninos+n);
	sort(ninas, ninas+m);

	int pb = 0, pg = 0 ;
	int ans = 0 ;
	while( pb < n && pg < m )
	{
		if( abs( ninos[pb] - ninas[pg] ) < 2 )
		{
			ans ++;
			pb ++;
			pg ++;

		}
		else
		{
			if( ninos[pb] < ninas[pg])
				pb++;
			else pg ++;
		}
	}

	cout<<ans;
	cout<<"\n";
}
