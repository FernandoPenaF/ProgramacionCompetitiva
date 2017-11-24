/*
* Los chocolates del agente nieves - https://omegaup.com/arena/problem/chocolates#problems
* GUID : d16d6654
*/

#include <stdio.h>
#include <math.h>

int N;
int prices[1000];
int dp[1000][1000];

int getMaxPrice(int inf, int sup){
	int nivel = N - sup + inf;

	if(inf == sup)
		return prices[inf] * nivel;
	if(dp[inf][sup] == 0)
		dp[inf][sup] = fmax(getMaxPrice(inf + 1, sup) + prices[inf] * nivel, getMaxPrice(inf, sup - 1) + prices[sup] * nivel);
		return dp[inf][sup];
}

int main(int argc, char const *argv[]){
	int price;
	scanf("%d", &N);
	for(unsigned i = 0; i < N; i++) {
		scanf("%d", &price);
		prices[i] = price;
	}
	
	printf("%d\n", getMaxPrice(0, N - 1));
	return 0;
}