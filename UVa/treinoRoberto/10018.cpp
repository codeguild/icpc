//4 9339 
//5 45254 
//3 6666
#include <stdio.h>
int inverte(long int pa){
	int r = 0;
	while(pa > 0){
		r = r*10 + pa%10;
		pa = pa/10;
	}
	return r;
}
bool hePalindromo(long int pa){
	long int p = pa;
	int casas[20];
	int i = 0;
	while(pa > 0){
		casas[i] = pa%10;
		pa = pa/10;
		i++;
	}
	i--;
	for (int j = 0; j < i; j++){
		//printf("numero: %ld , posicao j: %d , %d posicao i: %d , %d\n",p, j, casas[j], i, casas[i]);
		if (casas[j] != casas[i]) return false;
		i--;
	}
	return true;
}
void resolve(long int i, long int pa){
	//printf("\npasso: %d , numero: %ld\n\n", i, pa);

	if(hePalindromo(pa)){
		printf("%ld %ld", i, pa);
	}
	else{
		pa = pa + inverte(pa);
		i++;
		resolve(i, pa);
	}
}

int main(){
	unsigned long int n;
	long int pa;
	long int interacoes = 0;
	scanf("%ld\n", &n);
	for (int i = 0; i < n; i++){
		scanf("%ld\n", &pa);
		resolve(interacoes, pa);
		printf("\n");
	}
	return 0;
}