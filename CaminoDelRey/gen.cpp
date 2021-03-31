#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define clr(x) memset( x, 0, sizeof(x))
using namespace std;

typedef long long int ll;
constexpr int maxn = 1e6;

struct nodo
{
    int x,y,p;
    string abs;
 
};

void input(string a, int lim)
{
	fstream casos;
	casos.open(a.c_str(), ios::out);
	int n,t;
	char aa = (((char) ((rand() % 7)+1) )+96) ;
	casos<<aa<<(rand()%7)+1<<"\n";
	char b = (((char) ((rand() % 7)+1) )+96);
	casos<<b<<(rand()%7)+1<<"\n";

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

	queue<nodo>cl;
	nodo raiz,hijo;
	char n,m,f,cc;
	bool vis[100][100] = {{false}};
	int vx[]={-1,-1,0,1,1,1,0,-1};
	int vy[]={0,1,1,1,0,-1,-1,-1};
	int fl[]={0,8,7,6,5,4,3,2,1};
	string pas[]={"U\n","RU\n","R\n","RD\n","D\n","LD\n","L\n","LU\n"};
	fin>>n>>m>>f>>cc;
	//return 0;
	vis[fl[(int(m)-48)]][(int(n)-96)]=true;
	cl.push({fl[(int(m)-48)],(int(n)-96),0,""});
	nodo ans;
	while(!cl.empty())
	{
	    raiz=cl.front();
	    cl.pop();
	   // cout<<char(raiz.x+97)<<" "<<raiz.y<<"\n";
	    if(raiz.x==fl[(int(cc)-48)] && raiz.y==(int(f)-96))
	    {
	       //cout<<raiz.p<<"\n"<<raiz.abs<<"\n";
	    	ans = raiz;
	        break;
	    }
	    for(int c=0; c<8; c++)
	    {
	        hijo=raiz;
	        hijo.x+=vx[c];
	        hijo.y+=vy[c];
	        if(hijo.x>0 && hijo.x<=8 && hijo.y>0 && hijo.y<=8 && !vis[hijo.x][hijo.y])
	        {
	            hijo.abs+=pas[c];
	            hijo.p++;
	            vis[hijo.x][hijo.y]=true;
	            cl.push(hijo);
	        }
	    }
	}
	casos<<ans.p<<"\n"<<ans.abs;
	queue< nodo > limpia;
	cl = limpia;
	///--- solution --///

}


int main () 
{

	srand( time( NULL ));
		int c = 20;
		for(; ~c; c--)
		{
			string pp = "caso";
			pp += to_string(c);
			pp += ".in";
			//input(pp,(int)1e5);
			output(pp);

		}

	
}
