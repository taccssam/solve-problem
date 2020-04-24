#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int a[9];
stack<int> s;
int btf(int i,int sum,int c) {
	if (c == 7) {
		if (sum == 100)return 1;
		else return 0;
	}

	for (int j = i+1;j < 9;j++) {
		s.push(j);
		if (btf(j, sum + a[j], c + 1) == 1)return 1;
		s.pop();
	}
	return 0;
}

int main() {

	for (int i = 0;i < 9;i++)cin >> a[i];
	btf(-1, 0, 0);
	int b[7];
	int k;
	for (int i = 0;i < 7;i++) {
		k =  s.top();
		s.pop();
		b[i] = a[k];
	}
	sort(b, b + 7);
	for (int i : b)cout << i << endl;

}
// 두개만 골라 빼는걸로 쉽게 할 수 있다 ! 뒤에서 부터 생각하기
//런타임 에러는 리턴값 안 적어줘서 뜬다....