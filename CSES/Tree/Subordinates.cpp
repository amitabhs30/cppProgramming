#include<bits/stdc++.h>
using namespace std;
 
const int SZ = 200005;
int n, m, x;
vector<int> adj[SZ];
int S[SZ];
 
void dfs(int u,int l, int p)
{
	S[u] = 1;
	
	for (int v: adj[u]) {
		if (v != p) {
			dfs(v, l+1, u);
			S[u] += S[v];
		}
	}	
}
 
int main() {
    cin >> n;
    
    for(int i = 2; i <=n ; i++) {
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(1, 0, 0);
    for(int i = 1; i <= n ; i++) {
        cout << S[i] - 1 << " ";
    }
}