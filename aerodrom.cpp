/*
* Aerodrom - https://omegaup.com/arena/problem/AERODROM
* GUID : 816891ed
*/

#include <iostream>
using namespace std;

int deskTimes[300001];

long optimalTime(long time, int n){
	long optimal = 0;
	for (int i = 0; i < n; i++){
		optimal += time / deskTimes[i];
	}
	return optimal;
}

int main(int argc, char const *argv[])
{
	long infLim = 0, supLim = 0, mid;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		deskTimes[i] = t;
		if(t > supLim)
			supLim = t;
	}

	supLim *= m;
	while(infLim < supLim){
		mid = (infLim + supLim) / 2;
		if(optimalTime(mid, n) < m)
			infLim = mid + 1;
		else
			supLim = mid;
	}
	cout << infLim;
	return 0;
}