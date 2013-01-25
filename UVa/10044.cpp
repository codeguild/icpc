#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<math.h>
#include<string.h>
#include<inttypes.h>
#include<ctype.h>
#include<algorithm>
#include<utility>
#include<limits.h>
#include<map>
#include<set>
#include<sstream>

using namespace std;

#ifdef MACRO 
	#define TRACE(x...) x
#else
	#define TRACE(x...)
#endif

#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")

#define MAXV 100001
#define MAXDEGREE 1001

typedef struct {
	int v;
	int weight;
} edge;

typedef struct {
	edge edges[MAXV+1][MAXDEGREE];
	int degree[MAXV+1];
	int nvertices;
	int nedges;
} graph;

void print_graph(graph *g)
{
	int i,j;
	for (i=1; i<=g->nvertices; i++) {
		printf("%d: ",i);
		for (j=0; j<g->degree[i]; j++)
			printf(" %d",g->edges[i][j].v);
		printf("\n");
	}
}

void initialize_graph(graph *g)
{
	int i;
	g -> nvertices = 0;
	g -> nedges = 0;
	for (i=1; i<=MAXV; i++) 
		g->degree[i] = 0;
}
void insert_edge(graph *g, int x, int y, bool directed)
{
	if (g->degree[x] > MAXDEGREE)
		printf("Warning: insertion(%d,%d) exceeds max degree\n",x,y);
	g->edges[x][g->degree[x]].v = y;
	g->degree[x]++;
	if (directed == false)
		insert_edge(g,y,x,true);
	else
		g->nedges++;
}

void trim2(string& str)
{
  string::size_type pos = str.find_last_not_of(' ');
  if(pos != string::npos) {
    str.erase(pos + 1);
    pos = str.find_first_not_of(' ');
    if(pos != string::npos) str.erase(0, pos);
  }
  else str.erase(str.begin(), str.end());
}


void splitg(string s, graph *g, map<string, int> *hash)
{
	string x1;
	string x2;
	istringstream ss( s );
	string s1;
	getline( ss, s1, ':' );
	istringstream ss1( s1 );
	set<int> artigo;
	while (!ss1.eof())
	{
		getline( ss1, x1, ',' );
		getline( ss1, x2, ',' );
		trim2(x1);
		string pes = x1.substr(s.find_first_not_of(' ')) + string(",") + x2;
		map<string,int>::iterator it = hash->find(pes);
		if(it == hash->end())
			hash->insert(pair<string,int>(pes, hash->size()+1));
		it = hash->find(pes);
		for(set<int>::iterator it2 = artigo.begin(); it2 != artigo.end(); it2++)
		{
			insert_edge(g, it->second, *it2, false);
		}
		artigo.insert(it->second);
	}
}

int parent[MAXV];

/*int * dijkstra(graph *g, int start)
{
	int i,j;
	bool intree[MAXV];
	int distance[MAXV];
	int v;
	int w;
	int weight;
	int dist;
	for (i=1; i<=g->nvertices; i++) {
		intree[i] = false;
		distance[i] = INT_MAX;
		parent[i] = -1;
	}
	distance[start] = 0;
	v = start;
	while (intree[v] == false) {
		intree[v] = true;
		for (i=0; i<g->degree[v]; i++) {
			w = g->edges[v][i].v;
			weight = g->edges[v][i].weight;
			if (distance[w] > (distance[v]+weight)) {
				distance[w] = distance[v]+weight;
				parent[w] = v;
			}
		}
		v = 1;
		dist = INT_MAX;
		for (i=2; i<=g->nvertices; i++)
			if ((intree[i]==false) && (dist > distance[i])) {
				dist = distance[i];
				v = i;
			}
	}
	return distance;
}*/

int dist[100];

void rec(graph *g, int pos, int distancia)
{
	if (dist[pos] > distancia)
	{
		dist[pos] = distancia;
		for (int j = 0; j < g->degree[pos]; j++)
			rec(g, g->edges[pos][j].v, distancia+1);
	}
}

int main()
{
	int n;
	int nArt, nPes;
	scanf("%d", &n);
	char artigo[256];
	string pessoa;
	graph * g = new graph;
	initialize_graph(g);
	map<string, int> hash;
	hash.insert(pair<string,int>("Erdos, P.", 1));
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &nArt, &nPes);
		cin.getline(artigo, 256);
		for(int j = 0; j < nArt; j++)
		{
			cin.getline(artigo, 256);
			string sartigo(artigo);
			splitg(sartigo, g, &hash);
		}
		for(int j = 0; j < 10; j++)
			dist[j] = INT_MAX;
		rec(g, 1, 0);
		g->nvertices = hash.size();
		cout << "Scenario " << i+1 << endl;
		for(int j = 0; j < nPes; j++)
		{
			cin.getline(artigo, 256);
			pessoa = artigo;
			cout << pessoa << " ";
			map<string,int>::iterator it = hash.find(pessoa);
			int x = dist[it->second];
			if(x == INT_MAX)
				cout << "infinity" << endl;
			else
				cout << x << endl;

		}
	}
	return 0;
}
