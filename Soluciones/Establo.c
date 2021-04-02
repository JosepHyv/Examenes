#include<stdio.h>

char bosque[12][12];
int visitado[12][12];
int r,c,k;
int formas;

void soluciona(int x, int y, int pasos_disponibles)
{
	/// determino si es un estado invalido, si es asi, retorno y no
	/// proceso más
	if( x < 0 || x >= r || y < 0 || y >= c || pasos_disponibles < 1 || visitado[x][y] || bosque[x][y] == 'T' )
		return;
	/// debugeo
	fprintf(stderr,"%d -> %d  -> %d -> %c\n", x,y,pasos_disponibles,bosque[x][y]);

	/// pregunto si ya llegue 
	if( x == r-1 && y == 0 )
	{
		/// cuento una forma posible
		formas++;

		// esto es solo para que visualicen como ejemplo

		printf(" forma numero %d \n", formas);
		bosque[x][y] = 'a';
		for(int i = 0; i < r; i++ )
			printf("%s\n", bosque[i]);
		printf("\n");
		bosque[x][y] = '.';
		// esto es solo para que visualicen como ejemplo
		return;
	}

	// marco mis visitados y me muevo
	visitado[x][y] = 1;
	bosque[x][y] = pasos_disponibles + 'a' -1 ;/// esta actualizacion es solo para ejemplo de la visualizacion
	soluciona(x-1, y, pasos_disponibles-1);
	soluciona(x, y+1, pasos_disponibles-1);
	soluciona(x+1, y, pasos_disponibles-1);
	soluciona(x, y-1, pasos_disponibles-1);
	bosque[x][y] = '.'; // esto es solo para ejemplo de visualizacion 
	visitado[x][y] = 0 ;
	return;

}

int main()
{
	scanf("%d%d%d",&r,&c,&k);
	for(int i = 0 ; i < r; i++)
		for( int j = 0; j < c; j++)
			scanf(" %c",&bosque[i][j]);
	
	soluciona(0,c-1, k);
	printf("%d\n",formas);

}