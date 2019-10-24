#ifndef __LINKEDLIST
#define __LINKEDLIST
#include <iostream>
#pragma warning(disable:4290)
using namespace std;

class CompareValue
{
public:
	//T is a class - must have operator <, >
	template<class T>
	int operator()(const T* t1, const T* t2) const
	{
		if (*t1 < *t2)
			return 1;
		else if (*t1 > *t2)
			return -1;
		else
			return 0;
	}
};


template <class T>
class LinkedList
{
private:
	class iterator;
	class Node;

	int length;
	Node* head;
	Node* tail;
public:
	LinkedList();
	LinkedList(const LinkedList& list);
	LinkedList(LinkedList&& list);
	~LinkedList();

	const Node* getHead() const { return head; };
	const Node* getTail() const { return tail; };

	void setHead(Node * newHead) { head = newHead; };
	void setTail(Node * newTail) { tail = newTail; };
	const iterator begin() const { return iterator(head, head, tail); };
	const iterator end() const { return iterator(nullptr, head, tail); };

	int size() const { return length; }

	T& operator[](int index) throw (const string);
	const LinkedList<T>& operator=(const LinkedList<T>& other);

	template <class Comparator>
	void sort(const Comparator& compare);

	void clear();
	void add(const T& data);
	void removeIndex(int index) throw (const string);
	bool remove(const T& data);
};

template <class T>
class LinkedList<T>::Node
{
private:
	Node* next;
	Node* prev;
	T* data;
public:
	friend class LinkedList<T>;
	friend class LinkedList<T>::iterator;

	Node(const T& newData) { this->data = new T(newData); }
	Node(const Node& other) = delete;
	~Node() { delete data; }
	const T* getData() const { return this->data; }
	const Node* getNext() const { return next; }
	const Node* getPrev() const { return prev; }

	void setData(const T& data) { this->data = &data; }
	void setNext(Node* nextNode) { this->next = nextNode; };
	void setPrev(Node* prevNode) { this->prev = prevNode; };

	operator T&() { return *data; } 
};

template <class T>
class LinkedList<T>::iterator
{
private:
	Node* node;

	Node* head;
	Node* tail;
public:
	friend class LinkedList<T>;
	friend class LinkedList<T>::Node;

	iterator() : node(nullptr), head(nullptr), tail(nullptr) {};
	iterator(Node* pointer, Node* head, Node* tail) { node = pointer; this->head = head; this->tail = tail; };

	T& operator *() const throw (string) {
		if (node)
			return *((*node).data);
		else
			throw string("data in node is empty or corrupt");
	};

	iterator& operator++()
	{
		if (node)
			node = node->next;
		else
			node = head;
		return *this;
	}
	iterator& operator--()
	{
		if (node)
			node = node->prev;
		else
			node = tail;
		return *this;
	}

	bool operator==(const iterator& other) const { return (node == (other.node) ? true : false); };
	bool operator!=(const iterator& other) const { return !operator==(other); };

	friend ostream& operator<<(ostream& os, const iterator& it)
	{
		os << "Iterator point to " << **(it.node) << endl;
		return os;
	};
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
T& LinkedList<T>::operator[](int index) throw (const string)
{
	if (index >= length || index < 0)
		throw string("index out of bounds in LinkedList operator[]");
	LinkedList<T>::iterator iterEnd = end();
	int i = 0;
	for (LinkedList<T>::iterator iter = begin(); iter != iterEnd; ++iter, ++i)
	{
		if (i == index)
			return *iter;
	}
	throw string("index out of bounds - empty LinkedList");
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
	node->setNext(nullptr);
	node->setPrev(tail);
	if (head == nullptr)
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
	++length;
}

template<class T>
void LinkedList<T>::removeIndex(int index) throw (const string)
{
	if (index >= length || index < 0)
		throw string("index out of bounds in LinkedList");
	int count = 0;
	Node * current = head;
	while (count < length)
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

			--length;
			break;
		}
		current = current->next;
		++count;
	}
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
			removeIndex(count);
			return true;
		}
		cur = cur->next;
		++count;
	}
	return false;
}

template<class T>
template<class Comparator>
void LinkedList<T>::sort(const Comparator & compare)
{
	LinkedList<T>::iterator iter;
	LinkedList<T>::iterator iter2;
	LinkedList<T>::iterator iterEnd = end();

	for (int i = 0; i < length; ++i)
	{
		iter = begin();
		iter2 = begin();
		++iter2;
		while (iter !=iterEnd && iter2 !=iterEnd)
		{
			if (compare(*iter, *iter2) < 0)
			{
				std::swap(*iter, *iter2);
			}
			++iter;
			++iter2;
		}
	}
}

#endif //__LINKEDLIST