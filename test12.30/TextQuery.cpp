#include"TextQuery.h"
#include<memory>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
//TextQuery��Ա��������
TextQuery::TextQuery():text(make_shared<vector<string>>()), queryMap(make_shared<map<string, set<size_type>>>()) {}//Ĭ�Ϲ��캯��
TextQuery::TextQuery(ifstream& infile) :text(make_shared<vector<string>>()), queryMap(make_shared<map<string, set<size_type>>>()) {
	string line;
	while (getline(infile, line))
		text->push_back(line);//��һ�ж���text��
}//��������������

TextQuery TextQuery::query(const string& s) {
	auto ret = queryMap->insert({ s, set<size_type>() });//������������󣬻᷵��һ��pair
	if (ret.second) {
		//����ɹ�����ʱs��δ��ѯ
		auto beg = text->cbegin();//ָ��һ���ı��ĵ�����
		size_type lineNum = 1;//��ŵ�ǰ�к�
		while (beg!=text->cend()) {
			string word;//��Ŵ��鵥��
			istringstream line(*beg);//string����һ���ı�
			while (line >> word) {
				if (word == s) {
					//��ѯ��s����Ҫ����s���ִ������ͼ�¼�����к�

					ret.first->second.insert(lineNum);//����ǰ�к���ӵ�s��Ӧ��set��ȥ
					//����Ҫ����s���ֵĴ�����Ŀǰ��������ֵ���������
				}
			}
			++beg;//����������
			++lineNum;//һ�в�ѯ��ϣ��кŵ�����
		}
	}
	return *this;
}//���뵥�ʣ����в�ѯ

ostream &  TextQuery::print(ostream &os) {
	auto beg_map = this->queryMap->cbegin();//map�׵�����
	while (beg_map != this->queryMap->cend()) {
		//��map��˳���ӡĳ�����ʵĲ�ѯ���
		os << "the word" << ends << beg_map->first << " appears in: " << endl;
		auto beg_set = beg_map->second.cbegin();//���������set�׵�����
		while (beg_set != beg_map->second.cend()) {
			//��ӡÿ��
			os << "line: " << *beg_set << ", "
				<< (*this->text)[*beg_set-1] << endl;
			++beg_set;
		}
		os << "the result of " << beg_map->first << " ends here." << endl;
		++beg_map;
	}
	return os;
}//��ӡ����������