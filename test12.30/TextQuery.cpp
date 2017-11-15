#include"TextQuery.h"
#include<memory>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
//TextQuery成员函数定义
TextQuery::TextQuery():file(make_shared<vector<string>>()), queryMap(make_shared<map<string, set<line_no>>>()) {}//默认构造函数
TextQuery::TextQuery(ifstream& infile) : file(make_shared<vector<string>>()), queryMap(make_shared<map<string, set<line_no>>>()) {
	string line;
	while (getline(infile, line))
		file->push_back(line);//将一行读入text中
}//利用输入流构造

TextQuery TextQuery::query(const string& s)const {
	auto ret = queryMap->insert({ s, set<line_no>() });//关联容器插入后，会返回一个pair
	if (ret.second) {
		//插入成功，此时s还未查询
		auto beg = file->cbegin();//指向一行文本的迭代器
		line_no lineNum = 1;//存放当前行号
		while (beg!= file->cend()) {
			string word;//存放待查单词
			istringstream line(*beg);//string流绑定一行文本
			while (line >> word) {
				if (word == s) {
					//查询到s，需要递增s出现次数，和记录出现行号

					ret.first->second.insert(lineNum);//将当前行号添加到s对应的set中去
					//还需要递增s出现的次数，目前不清楚这个值存放在哪里
				}
			}
			++beg;//迭代器递增
			++lineNum;//一行查询完毕，行号递增；
		}
	}
	return *this;
}//输入单词，进行查询

ostream &  TextQuery::print(ostream &os)const {
	auto beg_map = this->queryMap->cbegin();//map首迭代器
	while (beg_map != this->queryMap->cend()) {
		//按map中顺序打印某个单词的查询结果
		os << "the word" << ends << beg_map->first << " appears in: " << endl;
		auto beg_set = beg_map->second.cbegin();//存放行数的set首迭代器
		while (beg_set != beg_map->second.cend()) {
			//打印每行
			os << "line: " << *beg_set << ", "
				<< (*this->file)[*beg_set-1] << endl;
			++beg_set;
		}
		os << "the result of " << beg_map->first << " ends here." << endl;
		++beg_map;
	}
	return os;
}//打印结果到输出流