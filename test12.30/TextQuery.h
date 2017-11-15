#pragma once
#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include<string>
#include<vector>
#include<map>
#include<set>
#include<memory>
#include<iostream>
using namespace std;
class TextQuery {
public:
	using size_type = vector<string>::size_type;
	//���캯������
	TextQuery();//Ĭ�Ϲ��캯��
	TextQuery(ifstream & infile);//��������������
	//��ѯ����
	TextQuery query(const string&);//���뵥�ʣ����в�ѯ,����
	ostream & print(ostream &os);//��ӡ����������
private:
	shared_ptr<vector<string>> text;//���������ļ�,Ϊ�ײ㹲������
	shared_ptr<map<string, set<size_type>>> queryMap;//�����ѯ���ʼ��к�
};//�ı����ѯ�������
class QueryResult;//��ѯ�����ӡ
#endif // !TEXTQUERY_H
