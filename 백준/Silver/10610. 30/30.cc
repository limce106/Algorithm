#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	string N;

	cin >> N;

	int sum = 0;
	int check_zero = 0;
	for (int i = 0; i < N.size(); i++) {
		sum += N[i] - '0';
		if (N[i] - '0' == 0) {
			check_zero = 1;
		}
	}

	if (sum % 3 != 0 || check_zero == 0) {
		cout << "-1" << endl;
		return 0;
	}

	sort(N.begin(),N.end(), greater<>()); //sort함수 사용 내림차순
	
	cout << N << endl;
	
	return 0;
}