//��ƺ����������ı���ѯ�������Ҫ�������裬Ϊ�������׼��
#include"TextQuery.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
//runQueries ��������һ��ָ�������ļ���������,��ɲ�ѯ�ʹ�ӡ���������
void runQueries(ifstream & infile) {
	//���������ı�
	TextQuery tq(infile);//ʹ����������Ϊ��������tq
	//�û�������������Ҫ��ѯ�ĵ��ʣ������ж����������ӡ���
	while (true) {
		cout << "������Ҫ��ѯ�ĵ��ʣ�����q�Ƴ���" << endl;
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s));//ʹ��print����������������Ͷ�q�Ĳ�ѯ������������ӡ����������Ե���s�Ĳ�ѯӦʹ��TextQuery�ĳ�Ա�������
	}
}