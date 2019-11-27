
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 11;
int A[maxn], B[maxn], ok[maxn][maxn];
int64_t C[maxn], suf[maxn], dp[maxn][maxn];

int main() {
	freopen("transform.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i != maxn; ++i) ok[i][0] = 1;
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		for (int i = 1; i <= N; ++i) cin >> A[i];
		for (int i = 1; i <= M; ++i) cin >> B[i];
		for (int i = 1; i <= N; ++i) cin >> C[i];
		suf[N + 1] = 0;
		for (int i = N; i; --i) suf[i] = suf[i + 1] + C[i];
		map<int, int> cnt, tot;
		for (int i = 1; i <= M; ++i) ++tot[B[i]];
		int64_t res = LLONG_MAX;
		for (int i = 1; i <= N; ++i) {
			int k1 = ++cnt[A[i]], k2 = tot[A[i]];
			dp[i][0] = dp[i - 1][0] + C[i];
			for (int j = 1, k3 = 0; j <= M; ++j) {
				ok[i][j] = 0;
				dp[i][j] = 1LL << 60;
				if (k2 == k3) {
					assert(A[i] != B[j]);
					if (ok[i - 1][j]) {
						ok[i][j] = 1;
						dp[i][j] = min(dp[i][j], dp[i - 1][j] + C[i]);
					}
				} else {
					if (A[i] == B[j]) {
						if (++k3 == k2) {
							if (ok[i - 1][j]) {
								ok[i][j] = 1;
								dp[i][j] = min(dp[i][j], dp[i - 1][j] + C[i]);
							}
						}
						if (ok[i - 1][j - 1]) {
							ok[i][j] = 1;
							dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
						}
					} else if (!k3) {
						if (ok[i - 1][j]) {
							ok[i][j] = 1;
							dp[i][j] = min(dp[i][j], dp[i - 1][j] + C[i]);
						}
					}
				}
			}
		}
//		for (int i = 1; i <= N; ++i) {
//			cerr << "i = " << i << " :" << endl;
//			for (int j = 1; j <= M; ++j) cerr << "j = " << j << " : ok = " << ok[i][j] << " dp = " << dp[i][j] << endl;
//		}
//		cout << "answer : ";
		if (ok[N][M]) cout << dp[N][M] << '\n';
		else cout << "No\n";
//		cout << endl;
	}
}
