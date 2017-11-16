#include "StrBlob.h"
#include<memory>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {};
StrBlob::StrBlob(std::initializer_list<std::string> i1) :data(std::make_shared<std::vector<std::string>>(i1) ){};
StrBlob::StrBlob(std::vector<std::string> i1) :data(std::make_shared<std::vector<std::string>>(i1)) {};

void StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
void StrBlob::pop_back()const {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
std::string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}
std::string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}
const string& StrBlob::back()const {
	check(0, "back on empty StrBlob");
	return data->back();
}

//StrBlobPtr成员函数定义
shared_ptr<vector<string>> StrBlobPtr::check(const string&msg) const{
	auto sptr = wptr.lock();
	if (!sptr)
		//表明wptr指向的元素不存在
		throw runtime_error("访问的对象不存在！");
	if (curr >= sptr->size())
		//说明curr下标越界
		throw out_of_range(msg);
	return sptr;
}

string& StrBlobPtr::deref() const {
	return (*check("解引用的下标越界"))[curr];
}
StrBlobPtr& StrBlobPtr::incr() {//如何构造一个StrBlobPtr对象？这里返回的是伴随指针的引用，表明是对自身递增操作；
	check("递增尾后位置！");
	++curr;
	return *this;
}