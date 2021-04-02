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
bool  tablero[12][12];  /// tablero de 8 * 8 
char fila, columna;
char tfila, tcolumna;
int arr[] = {0,8,7,6,5,4,3,2,1};

int main()
{
	/// el rey
	 //// la entrada a1
    /// tomo las letras de la a - h como columna
    /// y los numeros de 8 a 1 ( arriba hacia abajo en el tablero )
    /// los tomo alreves 1 a 8 siendo 1 el inicio del tablero 
    /// no necesariamente debe ser asi, es por comodidad simplemente
	cin>>columna>>fila;
	/*
		a8
		h1 */ 

	/// casilla t 

	cin>>tcolumna>>tfila;

	/// marcar el primer estado ( el padre )
	int a = (fila - 48);
	int b = (columna - 'a' +1) ;
	a = arr[a];

	//b = arr[b];

	tablero[a][b] = true;
	/*
		a8
		h1
	*/
	//cout<<" -> "<< a<<" "<<b<<"\n";
	padre.x = a;
	padre.y = b;
	padre.pasos = 0;
	padre.camino = "";
	cola.push(padre);
	//padre = {a,b,0,""};
	//cola.push( { a,b,0,""} );

	/// coordenadas de mi salida
	a = (tfila - 48);
	b = (tcolumna - 'a'+ 1)  ;
	a = arr[a];
	/// objetivo 

	/// este es el algoritmo general de bfs
	while( !cola.empty() )  /* cola.size() */ 
	{
		padre = cola.front();
		cola.pop();
		//cout<<padre.x<<" "<<padre.y<<" "<<padre.pasos<<"\n";
		/// voy a preguntar si ya llegue 
		if( padre.x == a && padre.y == b )
		{
			
			cout<<padre.pasos<<"\n";
			cout<<padre.camino;
			return 0;
		}

		/// movimiento hacia arriba ( U )
		if( padre.x-1 > 0  && !tablero[padre.x-1][padre.y])
		{
			cerr<<"pude meter U\n";
			estado hijo = padre;
			hijo.x -= 1;
			hijo.pasos ++;
			hijo.camino = hijo.camino + "U\n";
			tablero[hijo.x][hijo.y] = true;
			cola.push(hijo);
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
			cerr<<"pude meter R\n";
			estado hijo = padre;
			hijo.y += 1;
			hijo.pasos++;
			hijo.camino  = hijo.camino + "R\n";
			tablero[hijo.x][hijo.y] = true;
			cola.push(hijo);
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
			cerr<<"pude meter D\n";
			estado hijo = padre;
			hijo.x += 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "D\n";
			tablero[hijo.x][hijo.y] = true;
			cola.push(hijo);
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
			cerr<<"pude meter L\n";
			estado hijo = padre;
			hijo.y -= 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "L\n";
			tablero[hijo.x][hijo.y] = true;
			cola.push(hijo);
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
			cerr<<"pude meter LU\n";
			estado hijo = padre;
			hijo.x -= 1;
			hijo.y -= 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "LU\n";
			tablero[hijo.x][hijo.y] = true;
			cola.push(hijo);
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
			cerr<<"pude meter RU\n";
			estado hijo = padre;
			hijo.x -= 1;
			hijo.y += 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "RU\n";
			tablero[hijo.x][hijo.y] = true;
			cola.push(hijo);
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
			cerr<<"pude meter RD\n";
			estado hijo = padre;
			hijo.x += 1;
			hijo.y += 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "RD\n";
			tablero[hijo.x][hijo.y] = true;
			cola.push(hijo);
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
			cerr<<"pude meter LD\n";
			estado hijo = padre;
			hijo.x += 1;
			hijo.y -= 1;
			hijo.pasos ++;
			hijo.camino  = hijo.camino + "LD\n";
			tablero[hijo.x][hijo.y] = true;
			cola.push(hijo);
			/*
				camino = hola

				camino = camino + U ( holaU ) <- 
				camino = U + camino ( Uhola )  X
				camino += U ( holaU ) <-
			*/
		}


	}

}


