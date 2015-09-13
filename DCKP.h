#ifndef DCKP_H_INCLUDED
#define DCKP_H_INCLUDED
#define TAILLE_MAX 27
#define MIN(X,Y) X<Y?X:Y
#define MAXN 10000000
#define MINN -10000000
struct probleme
{
	int C;
	int n;
	int nc;
	int *v;
	int *p;
	int *tabindice;
	int **cp;
	int **cp1;
	
};

struct solution
{
	int n;// Le nombre des objets
	int objval;//La valeur de la fonction objctif (profit total des objets selectionnes)
	int volact;//Le volume total des objets selectionnés
	int *elem;//Un pointeur sur un tabelau précisant les objets sélectionnés (0 ou 1)
	int nbelem;//Le nombre des éléments pris (sélectionnés)

};
typedef struct probleme * pdckp;
typedef struct solution * soldckp;
typedef struct liste_tabou *lt;
typedef struct 
{
	int n;
    soldckp *tabs;
  //	int **icouples;
}population;





pdckp  chargement_prob(char * instance);
soldckp  build_init_sol(pdckp pb);
soldckp  build_empty_sol(pdckp pb);
// GENETIQUE
int test_comptBasique(pdckp pb,soldckp s,int bi);
population* build_population(int n, pdckp pb);
soldckp algo_gen_dckp(population *pop, pdckp pb);
///
void recherche_tabouBD(soldckp s,pdckp pb);
void intensifier_solution(soldckp s,pdckp pb);
void recherche_tabou(soldckp s,pdckp pb);
void recherche_local(soldckp s,pdckp pb);
void diversification(soldckp s,pdckp pb);
void intensification1(soldckp s,pdckp pb);
int test_compTB(pdckp pb,soldckp s, int a,int b,int c, int d);
int verifie_listetabou(int ** l,int *taille,int a,int b,int c ,int d);
int test_compatibilite(pdckp pb,soldckp s,int indice[]);
int test_compt(pdckp pb,soldckp s,int bi,int bj);
void copy_sol(soldckp s1, soldckp s2, pdckp pb);
void echange(int *tab,int,int);
void tri_rapide_bis(int tab1[],int tab2[],int tab3[],int debut,int fin);
void desallouer_prob(pdckp pb);
void desallouer_sol(soldckp s);
#endif // DCKP_H_INCLUDED