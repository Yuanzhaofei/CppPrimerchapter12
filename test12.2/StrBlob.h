#ifndef STRBLOB_H
#define STRBLOB_H
#include<string>
#include<vector>
#include<memory>
using namespace std;
/*定义StrBlob类，使用vect存放string对象，所有对象共享该vector。
*定义StrBlob的伴生指针类，指向string序列的某个string*/

class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	explicit StrBlob(std::initializer_list<std::string> i1);//使用初始化列表构造底层vector<string>对象
	explicit StrBlob(std::vector<std::string> i1);//使用初始化列表构造底层vector<string>对象
	size_type size()const { return data->size(); }//返回底层vector的大小
	bool empty() { return data->empty(); }//判断vector是否为空
	//添加和删除元素
	void push_back(const std::string &s) { data->push_back(s); } //末尾添加元素
	void push_back(const std::string &s) const{ data->push_back(s); }
	void pop_back();//删除末尾元素
	void pop_back()const;
	//访问元素
	std::string & front();//访问首元素
	const std::string & front() const;
	std::string & back();//访问尾元素
	const std::string & back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;//指向底层vector<string>的智能指针
	void check(size_type i, const std::string &msg) const;//如果下标i越界，则拍出异常，包含msg中的信息
	};

class StrBlobPtr {
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlobPtr() :curr(0) { }
	StrBlobPtr(StrBlob& a, size_type sz = 0) :wptr(a.data), curr(sz) { }
	string& deref() const;//对vector<string>某元素的解引用操作，返回左值
	StrBlobPtr& incr();//前缀递增操作，返回一个新的伴随指针；
private:
	shared_ptr<vector<string>> check(const string&) const;//string传递异常信息
	weak_ptr<vector<string>> wptr;//使用weak_ptr指针指向StrBlob中的vector<string>，需要检查vector<string>对象是否存在
	size_type curr;//当前vector<string>中元素的下标值，需要检查
};

#endif