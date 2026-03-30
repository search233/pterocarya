#include <iostream>
#include <stack>
#include <string>
#define ll unsigned long long

using namespace std;

int main() {

//   std::cin.tie(0);
//   std::ios::sync_with_stdio(false);

  int T, n;
  for (cin >> T; T; --T) {
    stack<ll> s;

    for (cin >> n; n; --n) {
      string t; cin >> t;
      if (t == "push") {
        ll x; cin >> x; 
        s.push(x);
      } else if (t == "pop") {
        if (s.empty()) cout << "Empty\n";
        else s.pop();
      } else if (t == "query") {
        if (s.empty()) cout << "Anguei!\n";
        else cout << s.top() << '\n';
      } else {
        cout << s.size() << '\n';
      }
		}
	}
  return 0;
}