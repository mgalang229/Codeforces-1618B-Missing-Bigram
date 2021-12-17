#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string s[n - 2];
		for (int i = 0; i < n - 2; i++) {
			cin >> s[i];
		}
		string ans = "";
		for (int i = 0; i < n - 2; i++) {
			// always add the first bigram
			if (i == 0) {
				ans += s[i];
			}
			// if the 2nd character of the bigram is equal to the 1st character
			// of the next bigram, then we only need to add the 2nd character of the next bigram
			// otherwise, we must add the whole next bigram
			if (i + 1 < n - 2) {
				if (s[i][1] == s[i + 1][0]) {
					ans += string(1, s[i + 1][1]);
				} else {
					ans += s[i + 1];
				}
			}
		}
		// if the length of the answer is still less than n, then simply add 1 character at the end
		if ((int) ans.size() < n) {
			ans += string(1, s[0][0]);
		}
		cout << ans << '\n';
	}
	return 0;
}
