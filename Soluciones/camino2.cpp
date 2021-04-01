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
char fila, columna, tfila, tcolumna;
bool vis[100][100];

int vx[]={-1,-1,0,1,1,1,0,-1};
int vy[]={0,1,1,1,0,-1,-1,-1};

int fl[]={0,8,7,6,5,4,3,2,1};

string pas[]= {"U\n","RU\n","R\n","RD\n","D\n","LD\n","L\n","LU\n"} ;
//L, R, U, D, LU, LD, RU or RD

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
   //// la entrada a1
    /// tomo las letras de la a - h como columna
    /// y los numeros de 8 a 1 ( arriba hacia abajo en el tablero )
    /// los tomo alreves 1 a 8 siendo 1 el inicio del tablero 
    /// no necesariamente debe ser asi, es por comodidad simplemente
    cin>>columna>>fila>>tcolumna>>tfila;

/// convierto el formato LetraNumero de la entrada en numero numero
/// donde la coordenada (a,8) = (1,1)
    int b = columna -  char('a') +1;
    int a = fila - 48;

    /// debugueo
    cerr<<"mi fila y columna inicial \n";
    cerr<<fila<<" "<<columna<<" -> ("<<fl[a]<<","<<b<<")\n";
    /// debugueo

    vis[fl[a]][b]=true;
    cl.push({fl[a],b,0,""});

    b = tcolumna -  char('a') +1;
    a = tfila - 48;
    a = fl[a]; /// convuerto la fila 1 en 8 ( volteo el tablero)
    /// aclaro no es estrictamente necesario

    /// debugueo
    cerr<<"mi fila y columna final \n";
    cerr<<tfila<<" "<<tcolumna<<" -> ("<<a<<","<<b<<")\n";
    /// debugueo
    


    while(!cl.empty())
    {
        padre=cl.front();
        cl.pop();
       // cout<<padre.x<<" "<<padre.y<<" "<<padre.p<<"\n";
        if(padre.x == a && padre.y == b)
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