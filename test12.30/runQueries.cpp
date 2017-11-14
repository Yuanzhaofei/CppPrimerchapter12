//设计函数，包含文本查询程序的主要操作步骤，为类设计做准备
#include"TextQuery.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
//runQueries 函数接受一个指向输入文件的输入流,完成查询和打印结果的任务
void runQueries(ifstream & infile) {
	//保存输入文本
	TextQuery tq(infile);//使用输入流作为参数构造tq
	//用户交互，输入想要查询的单词（可能有多个），并打印结果
	while (true) {
		cout << "输入想要查询的单词，输入q推出。" << endl;
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s));//使用print函数，接受输出流和对q的查询结果，将结果打印到输出流，对单词s的查询应使用TextQuery的成员函数完成
	}
}