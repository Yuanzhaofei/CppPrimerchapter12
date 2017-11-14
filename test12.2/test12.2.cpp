#include"StrBlob.h"
#include<vector>
#include<string>
#include<iostream>
#include<iterator>
#include<new>

using namespace std;
int main() {
	istream_iterator<string> str_it(cin),str_eof;
	vector<string> vs(str_it,str_eof);
	StrBlob sb(vs);
	StrBlobPtr sbPtr(sb);
	auto cnt = sb.size();//获得string序列元素数量
	for (decltype(cnt) k = 0; k != cnt; ++k) {
		cout << sbPtr.deref() << ends;
		sbPtr.incr();
	}
	using arrT = int[32];
	arrT a;
	system("pause");
	return 0;
}