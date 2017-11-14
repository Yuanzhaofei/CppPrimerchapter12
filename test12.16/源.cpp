#include<memory>
#include<iostream>
using namespace std;
int main() {
	unique_ptr<int> up(new int(4)), up2(up.release());
	cout << *up2 << endl;
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	using IntP = unique_ptr<int>;
	IntP p1(pi); 
	weak_ptr<int> wp = p1;
	cout << ix << endl;
	cout << *pi2;
	system("pause");
	return 0;
}