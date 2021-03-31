#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m;
int vx[100002];
int vy[100002];
int ans;

int main()
{
	scanf("%d",&n);
	for(int c = 0; c<n; c++ )
		scanf("%d",&vx[c]);
	scanf("%d",&m);
	for(int c = 0; c<m; c++ )
		scanf("%d",&vy[c]);

	sort(vx, vx+n);
	sort(vy, vy+m);

	int it = 0;
	for(int c = 0 ; c<n && it < m; )
	{
		//printf("%d ->  %d \n", vx[c], vy[it] );
		if(abs(vx[c] - vy[it]) < 2)
		{
			it++;
			c++;
			ans++;
		}
		else
		{
			if( vx[c] < vy[it])
				c++;
			else it++;
		}

	}
	printf("%d\n",ans);
}