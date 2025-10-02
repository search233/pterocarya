#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("/home/yangz/YZW/code/#vscode_Workspace/#For_cpp/check/diff.log", "w", stdout);

	system("cd /home/yangz/YZW/code/#vscode_Workspace/#For_cpp/check/src/");
	system("g++ -std=c++23 data.cpp -o ../compiled/data");
	system("g++ -std=c++23 std_code.cpp -o../compiled/std_code");
	system("g++ -std=c++23 my_code.cpp -o ../compiled/my_code");

	int t = 0;
	while(1){
		t++;
		system("../compiled/data > ../io/in.txt");
		system("../compiled/std_code  < ../io/in.txt  > ../io/std_code.out");
		system("../compiled/my_code  < ../io/in.txt  > ../io/my_code.out");

		if(system("diff ../io/std_code.out ../io/my_code.out > ../io/out.txt")){
			cout << "\nF*cking WA On Test " << t << '\n';
			break;
		}


		cout << " AC On Test " << t;
		if (t % 5 == 0) cout << '\n';

		// system("  > ../diff.log");
		if (t >1000) {
			return 0;
		}
	}
	return 0;
}
