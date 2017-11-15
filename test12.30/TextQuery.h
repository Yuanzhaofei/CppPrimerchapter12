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
	using line_no = vector<string>::size_type;
	//���캯������
	TextQuery();//Ĭ�Ϲ��캯��
	TextQuery(ifstream & infile);//��������������
	//��ѯ����
	TextQuery query(const string&)const;//���뵥�ʣ����в�ѯ������ɳ�����Ա��������Ϊ����ָ�����ݳ�Ա�����ܱ��ı�
	ostream & print(ostream &os)const;//��ӡ����������
private:
	shared_ptr<vector<string>> file;//���������ļ�,Ϊ�ײ㹲������
	shared_ptr<map<string, set<line_no>>> queryMap;//�����ѯ���ʼ��кţ���α����ܴ����أ�
};//�ı����ѯ�������
class QueryResult;//��ѯ�����ӡ
#endif // !TEXTQUERY_H
