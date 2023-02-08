#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
    for(int i=0;i<N;i++) {
        if (S[i]=='1') {
            cout << -1 << endl;
			return 0;
        }
    }

    int ans = 0;
    for(int i=0;i<N;i++) {
        if (S[i]=='4') {
            S[i] = '2';
            ans++;
        }
        if (S[i]=='9') {
            S[i] = '3';
            ans++;
        }
    }
    queue<pair<string,int> > q;
    q.push(make_pair(S, ans));
    set<string> pushed;
    pushed.insert(S);
    while (!q.empty()) {
        string s = q.front().first;
        int c = q.front().second;
        q.pop();
        ans = max(ans, c);
        c++;
        if (s.size() >= 2) {
            for(int i=0;i<s.size()-1;i++) {
                if (s[i]=='2' && s[i+1]=='5') {
                    string t = s.substr(0,i) + '5' + s.substr(i+2);
                    if (pushed.find(t)==pushed.end()) {
                        q.push(make_pair(t, c));
                        pushed.insert(t);
                    }
                }
                if (s[i]=='3' && s[i+1]=='6') {
                    string t = s.substr(0,i) + '6' + s.substr(i+2);
                    if (pushed.find(t)==pushed.end()) {
                        q.push(make_pair(t, c));
                        pushed.insert(t);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}