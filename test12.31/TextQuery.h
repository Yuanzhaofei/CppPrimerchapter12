#pragma once
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


class QueryResult;//��ѯ���

//TextQuery�࣬���������ļ����������ʺͳ��ֵ���������map�У����ڲ�ѯ
class TextQuery {
public:
	using line_no = vector<string>::size_type;//��������
	//���캯������
	TextQuery(ifstream & infile);//��������������
	QueryResult query(const string&)const;//���뵥�ʣ����в�ѯ������ɳ�����Ա��������Ϊ����ָ�����ݳ�Ա�����ܱ��ı�
private:
	shared_ptr<vector<string>> file;//���������ļ������������๲������Ϊ��������Ҫ��ӡ����������
	map<string, shared_ptr<set<line_no>>> wm;//�����ѯ���ʼ��кţ��к���Ҫ�������������࣬����ʹ�ö�̬�ڴ汣��
};

//�����������࣬��TextQuery�Ĳ�ѯ����query���أ����������ѯ�����Ҫ������Ԫ��
class QueryResult {
	friend ostream &print(ostream &os, const QueryResult & qr);//��ӡ�����������Ԫ����
public:
	using line_no = vector<string>::size_type;//��������
	QueryResult(string s, shared_ptr<set<line_no>> l, shared_ptr<vector<string>> f) :sought(s), lines(l),file(f){}
private:
	string sought;//��ѯ�ĵ���
	shared_ptr<set<line_no>> lines;//ָ���кŵ�shared_ptr
	shared_ptr<vector<string>> file;//ָ�������ļ���shared_ptr
};
#endif // !TEXTQUERY_H