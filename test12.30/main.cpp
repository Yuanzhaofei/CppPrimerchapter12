//��ƺ����������ı���ѯ�������Ҫ�������裬Ϊ�������׼��
#include"TextQuery.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
void runQueries(ifstream & infile);
int main() {
	ifstream infile("test_book.txt");
	runQueries(infile);
	system("pause");
	return 0;
}
//runQueries ��������һ��ָ�������ļ���������,��ɲ�ѯ�ʹ�ӡ���������
void runQueries(ifstream & infile) {
	//���������ı�
	TextQuery tq(infile);//ʹ����������Ϊ��������tq
	//�û�������������Ҫ��ѯ�ĵ��ʣ������ж����������ӡ���
	while (true) {
		cout << "������Ҫ��ѯ�ĵ��ʣ�����q�˳���" << endl;
		string s;
		if (!(cin >> s) || s == "q") break;
		tq.query(s);//ʹ��print������������������������ӡ����������Ե���s�Ĳ�ѯӦʹ��TextQuery�ĳ�Ա�������
	}
	tq.print(cout) << "all results end here.";//���������һ���´�ӡ���н����
}