#include <stdio.h>
int dp[5000][5000];
char s[5000], t[5000];
int mod = 1000000007;

int main(int argc, char const *argv[]){
	int resp = 0;
	unsigned i, j;
	scanf("%s", &s);
	scanf("%s", &t);

	for(i = 0; s[i]; i++) {
		for(j = 0; t[j]; j++) {
			dp[i + 1][j + 1] = (dp[i + 1][j] + (t[j] == s[i]) * (dp[i][j] + 1)) % mod;
		}
	}
	for(i = 0; i < s[i]; i++) {
		resp = (resp + dp[i + 1][j]) % mod;
	}
	printf("%d\n", resp);
	scanf("%d", &resp);
	return 0;
}