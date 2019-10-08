// https://omegaup.com/arena/problem/tecnm-19-red-prueba

#include "bits/stdc++.h"

#define endl '\n'
#define forn(i, n) for(int i=0;i<n;i++)
#define lli long long int
#define pii pair<int,int>
#define fi first
#define se second
#define psi pair<int,pii>
#define pb push_back
#define vi vector<int>
#define vii vector< vi >

using namespace std;

const int MAXN = 10010;

int cont;
int p[MAXN];
map<string, int> check;

int Find(int u) { return p[u] == u ? u : p[u] = Find(p[u]); }
void Union(int u,int v) {
	int Ru = Find(u), Rv = Find(v);
	if(Ru == Rv) return;
	p[Rv] = Ru;
}

int mapea(string a) {
	if(check.find(a) == check.end()) check[a] = cont++;
	return check[a];
}

// чтение и перевод это будет пустой тратой времени
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	forn(i, MAXN) p[i] = i;
	int n;
	cin>>n;
	assert(1 <= n && n <= 100);
	string city;
	forn(i, n) {
		int a;
		cin>>a;
		assert(1 <= a && a <= 100);
		int pr = -1;
		while(a--) {
			cin>>city;
			if(pr != -1) Union(pr, mapea(city));
			pr = mapea(city);
		}
	}

	string a,b;
	cin>>a>>b;
	if(Find(mapea(a)) == Find(mapea(b))) cout<<"posible"<<endl;
	else cout<<"imposible"<<endl;
	return 0;
}
