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



class Node;

template <class T>
class LinkedList
{
private:
	class iterator
	{
		friend class LinkedList;
	private:
		Node** node;
		Node** tail;
		iterator(Node* pointer) { node = &pointer; };

		T* operator *() { 
			if (*node != nullptr)
			{
				cout << "data is null!" << ((*node)->data) << endl;
				cout << "returning data" << endl;
				if ((*node)->data == nullptr)
					cout << "data is null!" << (*(*node)->data) << endl;
				return (*node)->data;
			}
				
			else
			{
				cout << "returning null" << endl;
				return nullptr;
			}
				
		};

		void goToEnd() 
		{
			while (*node != nullptr)
				++*this;
		}
		iterator& operator++()
		{
			if ((*node)->next == nullptr)
				tail = node;
			if (*node != nullptr)
				node = &((*node)->next);
			return *this;
		}
		iterator& operator--()
		{
			if (*node != nullptr && (*node)->prev != nullptr)
				node = &((*node)->prev);
			else if (*node == nullptr)
				node = tail;
			return *this;
		}

		bool operator==(const iterator& other) { cout << node << " vs " << (other.node) << endl; return node == (other.node) ? true : false; };
		bool operator!=(const iterator& other) { return !operator==(other); };

		friend ostream& operator<<(ostream& os, const iterator& it)
		{
			os << "Iterator point to " << **(it.node) << endl;
			return os;
		};
	};
	class Node
	{
		friend class LinkedList<T>;
		friend class iterator;
		Node* next;
		Node* prev;
		T* data;
	public:
		Node(const T& newData) { data = new T(newData); };
		~Node() { delete data; };
		T* getData() { return data; };
		Node* getNext() { return next; };
		Node* getPrev() { return prev; };

		void setData(const T& data) { data = &data; }
		void setNext(Node* nextNode) { next = nextNode; };
		void setPrev(Node* prevNode) { prev = prevNode; };

		operator T*() { return data; };

		friend ostream & operator<<(ostream & os, const Node & node)
		{
			
			return os;
		};
	};

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
	int size() const { return length; };
	iterator End() { iterator i(tail); i.goToEnd(); return i; };
	iterator Begin() { return iterator(head); };
	T* operator[](int index);
	const LinkedList<T>& operator=(const LinkedList<T>& other);


	friend ostream & operator<<(ostream & os, const LinkedList<T> & l);

	template <class Comparator>
	void sort(const Comparator& compare);
	void clear();
	void add(const T& data);
	void remove(int index);
	//throw (const char*);
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
	head = std::move(list.head);
	tail = std::move(list.tail);
}


template <class T>
LinkedList<T>::~LinkedList() {
	clear();
}

template<class T>
T* LinkedList<T>::operator[](int index)
{
	cout << "in operator[] LinkedList" << endl;
	if (index >= length || index < 0)
		throw "index out of bounds in LinkedList operator[]";
	iterator iter = Begin();
	iterator iterEnd = End();
	int i = 0;
	while(iter != iterEnd)
	{
		cout << "here" << endl;
		if (i == index)
		{
			cout  << "*iter " << iter << endl;
			return *iter;
		}
			
		++iter;
		++i;
	}
	if (head != nullptr)
		return *Begin();
	else throw "index out of bounds";
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
void LinkedList<T>::remove(int index)
//throw (const char*)
{
	//if (index >= length || index < 0)
	//	throw "index out of bounds in LinkedList";
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
	os << "LinkedList of type " << typeof(T).name() << "." << endl << "Length: " << l.length << endl;
	os << "Head is " << l.head << endl;
	os << "Tail is " << l.tail << endl;
	int i = 1;
	while (head->next) {
		os << i << ". " << head << endl;
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