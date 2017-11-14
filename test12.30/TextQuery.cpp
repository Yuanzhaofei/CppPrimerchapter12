#include"TextQuery.h"
#include<memory>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
//TextQuery��Ա��������
TextQuery::TextQuery():text(make_shared<vector<string>>), queryMap(make_shared<map<string, set<size_type>>>) {}//Ĭ�Ϲ��캯��
TextQuery::TextQuery(ifstream& infile) :text(make_shared<vector<string>>), queryMap(make_shared<map<string, set<size_type>>>) {
	string line;
	while (getline(infile, line))
		text->push_back(line);//��һ�ж���text��
}//��������������

void TextQuery::query(const string& s) {
	auto ret = queryMap->insert({ s, set<size_type>() });//������������󣬻᷵��һ��pair
	if (ret.second) {
		//����ɹ�����ʱs��δ��ѯ
		auto beg = text->begin();//ָ��һ���ı��ĵ�����
		size_type lineNum = 1;//��ŵ�ǰ�к�
		while (beg!=text->end()) {
			string word;//��Ŵ��鵥��
			istringstream line(*beg);//string����һ���ı�
			while (line >> word) {
				if (word == s) {
					//��ѯ��s����Ҫ����s���ִ������ͼ�¼�����к�
					ret.first->second.insert(lineNum);//����ǰ�к���ӵ�s��Ӧ��set��ȥ
					//����Ҫ����s���ֵĴ�����Ŀǰ��������ֵ���������
				}
			}
			++lineNum;//һ�в�ѯ��ϣ��кŵ�����
		}
	}
}//���뵥�ʣ����в�ѯ