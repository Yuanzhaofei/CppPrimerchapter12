#pragma once
#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include<string>
#include<vector>
#include<map>
#include<set>
#include<memory>
using namespace std;
class TextQuery {
public:
	using size_type = vector<string>::size_type;
	//构造函数定义
	TextQuery();//默认构造函数
	TextQuery(ifstream & infile);//利用输入流构造
	//查询函数
	void query(const string&);//输入单词，进行查询
private:
	shared_ptr<vector<string>> text;//保存输入文件,为底层共享数据
	shared_ptr<map<string, set<size_type>>> queryMap;//保存查询单词及行号
};//文本与查询结果保存
class QueryResult;//查询结果打印
#endif // !TEXTQUERY_H
