#include<stdio.h>

int cuenta[100002];
int vx[100002];
int esta[100002];
int esta2[100002];
int rep;

int main()
{
	long long ans = 0 ;
	int n;
	scanf("%d",&n);
	for(int c = 0 ; c<n; c++)
	{
		scanf("%d",&vx[c]);
		cuenta[vx[c]] = rep;
		if( !esta[vx[c]] )
		{
			esta[vx[c]] = 1;
			rep++;
		}

	}
	for(int c = 0 ; c<n; c++)
	{
		if(!esta2[vx[c]])
		{
			esta2[vx[c]] = 1;
			ans += cuenta[vx[c]];
		}
	}
	printf("%lld\n",ans);
}
