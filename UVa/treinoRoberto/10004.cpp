#include <stdio.h>
void poe(nt no[][], int node, int i, bool * bicolorable, bool * notBicolorable){
	if (notBicolorable && !bicolorable){
		printf ("NOT BICOLORABLE");
		bicolorable = false;
	}
}

void busca(int no[][], int node, bool * bicolorable, bool * notBicolorable){
	for(int i = 2; i <= no[node][1]; i++){
		if(no[node][i]<201) {
			poe(no, node, i, &bicolorable, &notBicolorable);
		}	
	}
}

int main(){
	int nNos, nEdges, node, edge;
	bool bicolorable = true;
	bool notBicolorable = false;
	scanf("%d\n", n);
	while (nNos != 0){
		scanf("d\n", nEdges);
		int no[nNos][nNos+2][2];
		for(int i = 0; i < n; i++){
			if(no[node][1] == 0){
				no[node][1] = 1;
			}
			scanf("%d\n %d\n", node, edge);
			no[node][1]++;
			no[node][no[node][1]] = edge;
		}
		busca(no, 0, &bicolorable);
		
	}
	int ColorNode[node][node+1];
	run();
	if (Bicolorable) printf ("BICOLORABLE");
	return 0;
}