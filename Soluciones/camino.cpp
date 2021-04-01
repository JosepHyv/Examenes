#include<queue>
#include<iostream>
using namespace std;

struct estado
{
	int x,y; 
	int pasos; 
	string camino;
};

estado padre;
queue < estado > cola;
int  tablero[12][12];  /// tablero de 8 * 8 
char fila, columna;
char tfila, tcolumna;
int arr[] = {0, 8,7,6,5,4,3,2,1};

int main()
{
	/// el rey
	cin>>columna>>fila;
	/*
		a8
		h1 */ 

	/// casilla t 

	cin>>tcolumna>>tfila;

	/// marcar el primer estado ( el padre )
	int a = (fila - 48);
	int b = (columna - ( int('a') -1) ) ;
	a = arr[a];
	//b = arr[b];

	tablero[a][b] = true;
	/*
		a8
		h1
	*/
	padre.x = a;
	padre.y = b;
	padre.pasos = 0;
	padre.camino = "";

	/// coordenadas de mi salida
	a = (tfila - 48);
	b = (tcolumna - ( int('a') -1) ) ;
	a = arr[a];
	//b = arr[b];
	/// objetivo 

	//padre = {a,b,0,""};
	cola.push(padre);
	//cola.push( { a,b,0,""} );


	/*cout<<"mi coordenada inicial\n";
	cout<<padre.x<<" "<<padre.y<<"\n";
	cout<<"mi coordenada meta\n";
	cout<<a<<" "<<b<<"\n";
	return 0;*/
	/// este es el algoritmo general de bfs
	while( !cola.empty() /* cola.size() */ )
	{
		padre = cola.front();
		cola.pop();
		cout<<padre.x<<" "<<padre.y<<" "<<padre.pasos<<"\n";
		/// voy a preguntar si ya llegue 
		if( padre.x == a && padre.y == b )
		{
			cout<<"jhska\n";
			cout<<padre.pasos<<"\n";
			cout<<padre.camino;
			return 0;
		}

		/// movimiento hacia arriba ( U )
		if( padre.x-1 > 0  && !tablero[padre.x-1][padre.y])
		{
			estado hijo = padre;
			hijo.x -= 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "U\n";
			tablero[hijo.x][hijo.y] = true;
			/*
				camino = hola

				camino = camino + U ( holaU ) <- 
				camino = U + camino ( Uhola )  X
				camino += U ( holaU ) <-
			*/
		}
		// la derecha ( R ) 
		if(  padre.y+1 < 9 && !tablero[padre.x][padre.y+1])
		{
			cout<<"meti algo\n";
			estado hijo = padre;
			hijo.y += 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "R\n";
			tablero[hijo.x][hijo.y] = true;
			/*
				camino = hola

				camino = camino + U ( holaU ) <- 
				camino = U + camino ( Uhola )  X
				camino += U ( holaU ) <-
			*/
		}
		// abajo ( D ) 
		if( padre.x+1 < 9  && !tablero[padre.x+1][padre.y])
		{
			estado hijo = padre;
			hijo.x += 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "D\n";
			tablero[hijo.x][hijo.y] = true;
			/*
				camino = hola

				camino = camino + U ( holaU ) <- 
				camino = U + camino ( Uhola )  X
				camino += U ( holaU ) <-
			*/
		}
		// izquierda ( L ) 
		if(  padre.y-1 > 0  && !tablero[padre.x][padre.y-1])
		{
			estado hijo = padre;
			hijo.y -= 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "L\n";
			tablero[hijo.x][hijo.y] = true;
			/*
				camino = hola

				camino = camino + U ( holaU ) <- 
				camino = U + camino ( Uhola )  X
				camino += U ( holaU ) <-
			*/
		}
		/// diagonal  izquierda arriba ( LU )
		if( padre.x-1 > 0 && padre.y-1 > 0  && !tablero[padre.x-1][padre.y-1])
		{
			estado hijo = padre;
			hijo.x -= 1;
			hijo.y -= 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "LU\n";
			tablero[hijo.x][hijo.y] = true;
			/*
				camino = hola

				camino = camino + U ( holaU ) <- 
				camino = U + camino ( Uhola )  X
				camino += U ( holaU ) <-
			*/
		}
		// diagonal derecha arriba ( RU)
		if( padre.x-1 > 0  && padre.y+1 < 9 && !tablero[padre.x-1][padre.y+1])
		{
			estado hijo = padre;
			hijo.x -= 1;
			hijo.y += 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "RU\n";
			tablero[hijo.x][hijo.y] = true;
			/*
				camino = hola

				camino = camino + U ( holaU ) <- 
				camino = U + camino ( Uhola )  X
				camino += U ( holaU ) <-
			*/
		}
		/// diagonal derecha abajo ( RD)
		if( padre.x+1 < 9 && padre.y +1 < 9 && !tablero[padre.x+1][padre.y+1])
		{
			estado hijo = padre;
			hijo.x += 1;
			hijo.y += 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "RD\n";
			tablero[hijo.x][hijo.y] = true;
			/*
				camino = hola

				camino = camino + U ( holaU ) <- 
				camino = U + camino ( Uhola )  X
				camino += U ( holaU ) <-
			*/
		}
		/// diagonal izquierda abajo ( LD)
		if( padre.x+1 < 9 && padre.y -1 > 0  && !tablero[padre.x+1][padre.y -1])
		{
			estado hijo = padre;
			hijo.x += 1;
			hijo.y -= 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "LD\n";
			tablero[hijo.x][hijo.y] = true;
			/*
				camino = hola

				camino = camino + U ( holaU ) <- 
				camino = U + camino ( Uhola )  X
				camino += U ( holaU ) <-
			*/
		}


	}

}


