#ifndef __LINKEDLIST
#define __LINKEDLIST
#include <iostream>

using namespace std;


class CompareValue
{
public:
	template<class T>
	int operator()(const T* t1, const T* t2) const
	{
		if (*t1 < *t2) return -1;
		else if (*t1 > *t2) return 1;
		else return 0;
	}
};

class ComparePointer
{
public:
	template<class T>
	int operator()(const T* t1, const T* t2) const
	{
		if (**t1 < **t2) return -1;
		else if (**t1 > **t2) return 1;
		else return 0;
	}
};





template <class T>
class LinkedList
{
public:
	class Node
	{
	public:
		friend class LinkedList;
	private:
		Node* next;
		Node* prev;
		T* data;

		Node(const T& newData) { data = new T(newData); }
		Node(const Node& other) = delete;
		~Node() { delete data; }
		T* getData() { return data; }
		Node* getNext() { return next; }
		Node* getPrev() { return prev; }

		void setData(const T& data) { data = &data; }
		void setNext(Node* nextNode) { next = nextNode; };
		void setPrev(Node* prevNode) { prev = prevNode; };

		operator T&() { return *data; }
	};
private:
	int length;
	Node* head;
	Node* tail;
public:
	LinkedList();
	LinkedList(const LinkedList& list);
	LinkedList(LinkedList&& list);
	~LinkedList();

	const Node* getHead() const { return head; }
	const Node* getTail() const { return tail; }
	int size() const { return length; }


	T& operator[](int index) throw (const char*);
	const LinkedList<T>& operator=(const LinkedList<T>& other);


	friend ostream & operator<<(ostream & os, const LinkedList<T> & l);

	template <class Comparator>
	void sort(const Comparator& compare);
	void clear();
	void add(const T& data);
	void remove(int index) throw (const char*);
	bool remove(const T& data);
};

template <class T>
LinkedList<T>::LinkedList() {
	this->length = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

template<class T>
inline LinkedList<T>::LinkedList(const LinkedList<T> & list)
{
	*this = list;
}

template<class T>
LinkedList<T>::LinkedList(LinkedList<T> && list)
{
	length = list.length;
	head = list.head;
	tail = list.tail;
	list.head = nullptr;
	list.tail = nullptr;
}


template <class T>
LinkedList<T>::~LinkedList() {
	clear();
}

template<class T>
T& LinkedList<T>::operator[](int index) throw (const char*)
{
	if (index >= length || index < 0)
		throw "index out of bounds in LinkedList operator[]";
	Node * cur = head;
	for (int i = 0; i < length; i++)
	{
		if (i == index)
			return (T)*cur;
		cur = head->next;
	}
	if (head != nullptr)
		return (T)*head;
	else throw "index out of bounds - empty LinkedList";
}

template<class T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	clear();
	Node * cur = other.head;
	while (cur != nullptr)
	{
		add(*(cur->data));
		cur = cur->next;
	}
	return *this;
}

template<class T>
void LinkedList<T>::clear()
{
	Node * cur = head;
	Node * next = nullptr;
	while (cur != nullptr)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
	length = 0;
	head = nullptr;
	tail = nullptr;
}

template <class T>
void LinkedList<T>::add(const T& data) {
	Node* node = new Node(data);
	cout << "adding to Node " << node << " data " << data << endl;
	node->setNext(nullptr);
	if (head == nullptr)
	{
		head = node;
		tail = node;
		node->setPrev(nullptr);
	}
	else
	{
		tail->setNext(node);
		node->setPrev(tail);
		tail = node;
	}
	++length;
}

template<class T>
void LinkedList<T>::remove(int index) throw (const char*)
{
	if (index >= length || index < 0)
		throw "index out of bounds in LinkedList";
	int count = 0;
	Node * current = head;
	while (count < length && index < count)
	{
		if (count == index)
		{
			if (current->prev != nullptr)
				current->prev->next = current->next;
			else
				head = current->next;

			if (current->next != nullptr)
				current->next->prev = current->prev;
			else
				tail = current->prev;

			delete current;
		}
		current = current->next;
		++count;
	}
	--length;
}

template<class T>
bool LinkedList<T>::remove(const T & data)
{
	Node * cur = head;
	int count = 0;
	while (cur != nullptr)
	{
		if (*(cur->getData()) == data)
		{
			remove(count);
			return true;
		}
		cur = cur->next;
		++count;
	}
	return false;
}


template <class T>
ostream & operator<<(ostream & os, const LinkedList<T> & l) {
	Node* head = l.head;
	os << "LinkedList<" << typeof(T).name() << "> " << "Length: " << l.length << endl;
	os << "Head is " << l.head << endl;
	os << "Tail is " << l.tail << endl;
	int i = 1;
	while (head->next) {
		os << i << ". " << *head << endl;
		head = head->next;
		++i;
	}
	return os;
}


template<class T>
template<class Comparator>
void LinkedList<T>::sort(const Comparator & compare)
{
	//cout << "sorting" <<*this << endl;;
	Node* current;
	for (int i = 0; i < length; ++i)
	{
		current = head;
		while (current != nullptr && current->next != nullptr)
		{
			if (compare((current->getData()), (current->next->getData())) > 0)
			{
				std::swap(current->data, current->next->data);
			}
			current = current->next;
		}
	}



}
#endif //__LINKEDLIST