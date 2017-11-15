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
	//构造函数定义
	TextQuery();//默认构造函数
	TextQuery(ifstream & infile);//利用输入流构造
	//查询函数
	TextQuery query(const string&)const;//输入单词，进行查询，定义成常量成员函数，因为两个指针数据成员都不能被改变
	ostream & print(ostream &os)const;//打印结果到输出流
private:
	shared_ptr<vector<string>> file;//保存输入文件,为底层共享数据
	shared_ptr<map<string, set<line_no>>> queryMap;//保存查询单词及行号，如何保存总次数呢？
};//文本与查询结果保存
class QueryResult;//查询结果打印
#endif // !TEXTQUERY_H
