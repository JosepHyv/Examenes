#include<queue>
#include<iostream>
using namespace std;

struct nodo
{
    int x,y,p;
    string camino;
};

queue<nodo>cl;
nodo padre,hijo;
char n,m,f,cc;
bool vis[100][100];

int vx[]={-1,-1,0,1,1,1,0,-1};
int vy[]={0,1,1,1,0,-1,-1,-1};

int fl[]={0,8,7,6,5,4,3,2,1};

string pas[]= {"U\n","RU\n","R\n","RD\n","D\n","LD\n","L\n","LU\n"} ;
//L, R, U, D, LU, LD, RU or RD

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m>>f>>cc;
    //return 0;
    vis[fl[(int(m)-48)]][(int(n)-96)]=true;
    cl.push({fl[(int(m)-48)],(int(n)-96),0,""});
 
    while(!cl.empty())
    {
        padre=cl.front();
        cl.pop();
       // cout<<padre.x<<" "<<padre.y<<" "<<padre.p<<"\n";
        if(padre.x==fl[(int(cc)-48)] && padre.y==(int(f)-96))
        {
            cout<<padre.p<<"\n"<<padre.camino;
            return 0;
        }
        for(int c=0; c<8; c++)
        {
            hijo=padre;
            hijo.x += vx[c];
            hijo.y += vy[c];
            if(hijo.x>0 && hijo.x<=8 && hijo.y>0 && hijo.y<=8 && !vis[hijo.x][hijo.y])
            {
                hijo.camino = hijo.camino + pas[c];
                hijo.p++;
                vis[hijo.x][hijo.y]=true;
                cl.push(hijo);
            }
        }
    }
}