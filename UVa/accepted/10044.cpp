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
#include<vector>
#include<list>

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
	vector< list<int> > edges;
	int degree[MAXV+1];
	int nvertices;
	int nedges;
} graph;

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
	if(g->edges.size() <= x)
		g->edges.resize(x+1);
	g->edges[x].push_front(y);
	if (directed == false)
		insert_edge(g,y,x,true);
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

vector<int> dist;

void rec(graph *g, int pos, int distancia)
{
	if (dist[pos] > distancia)
	{
		dist[pos] = distancia;
		for(list<int>::iterator it = g->edges[pos].begin(); it != g->edges[pos].end(); it++)
			rec(g, *it, distancia+1);
	}
}

int main()
{
	int n;
	int nArt, nPes;
	scanf("%d", &n);
	graph * g;
	char artigo[256];
	string pessoa;
	map<string, int> hash;
	for(int i = 0; i < n; i++)
	{
		g = new graph;
		initialize_graph(g);
		hash.clear();
		hash.insert(pair<string,int>("Erdos, P.", 1));
		g->edges.resize(2);
		scanf("%d %d", &nArt, &nPes);
		cin.getline(artigo, 256);
		for(int j = 0; j < nArt; j++)
		{
			cin.getline(artigo, 256);
			string sartigo(artigo);
			splitg(sartigo, g, &hash);
		}
		dist.resize(g->edges.size()+1);
		for(int j = 0; j < dist.size(); j++)
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
			if (it == hash.end())
				cout << "infinity" << endl;
			else
			{
				int x = dist[it->second];
				if(it->second >= dist.size() || x == INT_MAX)
					cout << "infinity" << endl;
				else
					cout << x << endl;
			}

		}
		delete g;
	}
	return 0;
}
