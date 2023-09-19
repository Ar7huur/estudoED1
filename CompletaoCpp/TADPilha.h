#define MAXP 10

struct TpPilha{
    int pilha[MAXP],topo;
};
void inicializa(TpPilha &P){
    P.topo= -1;
}
void insere(TpPilha &P,int elem){
    P.pilha[++P.topo]=elem;
}
int retira(TpPilha &P){
    return P.pilha[P.topo--];
}
int vazia (int topo){
    return topo == -1;
}
int cheia (int topo){
    return topo == MAXP-1;
}
int elemTopo(TpPilha P){
    return P.pilha[P.topo];
}
void exibe(TpPilha P){
    while(!vazia(P.topo))
        printf("\n %d ",retira(P));
}