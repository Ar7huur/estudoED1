#define MAXF 10

struct TpFila{
	int fim,fila[MAXF];
};
void inicializa(TpFila &f){
	f.fim=-1;
}
void insere(TpFila &f,int elem){
	f.fila[++f.fim]=elem;
}
int retira (TpFila &f){
	int aux,i;
	aux=f.fila[0];
	for(i=0;i<f.fim;i++)
		f.fila[i]=f.fila[i+1];
	f.fim--;
	return aux;	
}
int vazia(int fim){
	return fim== -1;
}
int cheia(int fim){
	return fim== MAXF-1;
}
void exibe(TpFila f){
	while(!vazia(f.fim))
		printf(" %d ",retira(f));
}
