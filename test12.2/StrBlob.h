#ifndef STRBLOB_H
#define STRBLOB_H
#include<string>
#include<vector>
#include<memory>
using namespace std;
/*����StrBlob�࣬ʹ��vect���string�������ж������vector��
*����StrBlob�İ���ָ���ָ࣬��string���е�ĳ��string*/

class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	explicit StrBlob(std::initializer_list<std::string> i1);//ʹ�ó�ʼ���б���ײ�vector<string>����
	explicit StrBlob(std::vector<std::string> i1);//ʹ�ó�ʼ���б���ײ�vector<string>����
	size_type size()const { return data->size(); }//���صײ�vector�Ĵ�С
	bool empty() { return data->empty(); }//�ж�vector�Ƿ�Ϊ��
	//��Ӻ�ɾ��Ԫ��
	void push_back(const std::string &s) { data->push_back(s); } //ĩβ���Ԫ��
	void push_back(const std::string &s) const{ data->push_back(s); }
	void pop_back();//ɾ��ĩβԪ��
	void pop_back()const;
	//����Ԫ��
	std::string & front();//������Ԫ��
	const std::string & front() const;
	std::string & back();//����βԪ��
	const std::string & back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;//ָ��ײ�vector<string>������ָ��
	void check(size_type i, const std::string &msg) const;//����±�iԽ�磬���ĳ��쳣������msg�е���Ϣ
	};

class StrBlobPtr {
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlobPtr() :curr(0) { }
	StrBlobPtr(StrBlob& a, size_type sz = 0) :wptr(a.data), curr(sz) { }
	string& deref() const;//��vector<string>ĳԪ�صĽ����ò�����������ֵ
	StrBlobPtr& incr();//ǰ׺��������������һ���µİ���ָ�룻
private:
	shared_ptr<vector<string>> check(const string&) const;//string�����쳣��Ϣ
	weak_ptr<vector<string>> wptr;//ʹ��weak_ptrָ��ָ��StrBlob�е�vector<string>����Ҫ���vector<string>�����Ƿ����
	size_type curr;//��ǰvector<string>��Ԫ�ص��±�ֵ����Ҫ���
};

#endif