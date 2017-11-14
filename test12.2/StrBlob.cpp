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

//StrBlobPtr��Ա��������
shared_ptr<vector<string>> StrBlobPtr::check(const string&msg) const{
	auto sptr = wptr.lock();
	if (!sptr)
		//����wptrָ���Ԫ�ز�����
		throw runtime_error("���ʵĶ��󲻴��ڣ�");
	if (curr >= sptr->size())
		//˵��curr�±�Խ��
		throw out_of_range(msg);
	return sptr;
}

string& StrBlobPtr::deref() const {
	return (*check("�����õ��±�Խ��"))[curr];
}
StrBlobPtr& StrBlobPtr::incr() {//��ι���һ��StrBlobPtr�������ﷵ�ص��ǰ���ָ������ã������Ƕ��������������
	check("����β��λ�ã�");
	++curr;
	return *this;
}