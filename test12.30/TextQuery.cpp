#include"TextQuery.h"
#include<memory>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
//TextQuery成员函数定义
TextQuery::TextQuery():text(make_shared<vector<string>>), queryMap(make_shared<map<string, set<size_type>>>) {}//默认构造函数
TextQuery::TextQuery(ifstream& infile) :text(make_shared<vector<string>>), queryMap(make_shared<map<string, set<size_type>>>) {
	string line;
	while (getline(infile, line))
		text->push_back(line);//将一行读入text中
}//利用输入流构造

void TextQuery::query(const string& s) {
	auto ret = queryMap->insert({ s, set<size_type>() });//关联容器插入后，会返回一个pair
	if (ret.second) {
		//插入成功，此时s还未查询
		auto beg = text->begin();//指向一行文本的迭代器
		size_type lineNum = 1;//存放当前行号
		while (beg!=text->end()) {
			string word;//存放待查单词
			istringstream line(*beg);//string流绑定一行文本
			while (line >> word) {
				if (word == s) {
					//查询到s，需要递增s出现次数，和记录出现行号
					ret.first->second.insert(lineNum);//将当前行号添加到s对应的set中去
					//还需要递增s出现的次数，目前不清楚这个值存放在哪里
				}
			}
			++lineNum;//一行查询完毕，行号递增；
		}
	}
}//输入单词，进行查询