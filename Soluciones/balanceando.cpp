#include<stack>
#include<vector>
#include<math.h>
#include<stdio.h>
using namespace std;


vector < int > pos[200002];
int vx[200002];
int n,m;
int ans;
//vector < int > sobrante;
stack < int > sobrante;

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int c = 0 ; c<n; c++)
	{
		scanf("%d",&vx[c]);
		pos[vx[c]%m].push_back(c);
	}

	for(int c = 0 ; c<2*m; c++)
	{
		int actual = c%m;
		int tam = n/m;
		while( (int)pos[actual].size() > tam)
		{
			int numero = pos[actual].back();
			pos[actual].pop_back();
			//sobrante.push_back(numero);
			sobrante.push(numero);
		}

		while( pos[actual].size() < tam  && sobrante.size() ) 
		{
			//int numero = sobrante.back();
			int numero = sobrante.top();
			//sobrante.pop_back();
			sobrante.pop();
			pos[actual].push_back(numero);
			ans += abs(c - ( vx[numero] % m ));
			vx[numero] += abs(c - ( vx[numero] % m ));
		}

	}
	printf("%d\n",ans);
	for(int c = 0 ; c<n; c++)
		printf("%d ", vx[c]);
	printf("\n");

}