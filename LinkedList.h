#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T> 
class LinkedList
{
	private:
		unsigned int count;
	public:
		struct Node;
		Node* head;
		Node* tail;
		void PrintForward() const;
		void PrintReverse() const;
		void PrintForwardRecursive(const Node* node) const;
		void PrintReverseRecursive(const Node* node) const;
		unsigned int NodeCount() const;
		void FindAll(vector<Node*>& outData, const T& value) const;
		const Node* Find(const T& data) const;
		Node* Find(const T& data);
		const Node* GetNode(unsigned int index) const;
		Node* GetNode(unsigned int index);
		Node* Head();
		const Node* Head() const;
		Node* Tail();
		const Node* Tail() const;
		void AddHead(const T& data);
		void AddTail(const T& data);
		void AddNodesHead(const T* data, unsigned int count);
		void AddNodesTail(const T* data, unsigned int count);
		void InsertAfter(Node* node, const T& data);
		void InsertBefore(Node* node, const T& data);
		void InsertAt(const T& data, unsigned int index);
		bool RemoveHead();
		bool RemoveTail();
		unsigned int Remove(const T& data);
		bool RemoveAt(unsigned int index);
		void Clear();
		const T& operator[](unsigned int index) const;
		T& operator[](unsigned int index);
		bool operator==(const LinkedList<T>& rhs) const;
		LinkedList<T>& operator=(const LinkedList<T>& rhs);
		LinkedList();
		LinkedList(const LinkedList<T>& list);
		~LinkedList();
};

template <typename T>
struct LinkedList<T>::Node
{
	Node* next = nullptr;
	Node* prev = nullptr;
	T data;
};

template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->AddHead((*list.head).data);
	unsigned int i;
	for (i = 1;i < list.count; i++)
	{
		this->AddTail(list[i]);
	}
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	if (this != &rhs)
	{
		this->Clear();
		unsigned int i;
		for (i = 0; i < rhs.count; i++)
		{
			this->AddTail(rhs[i]);
		}
	}
	return *this;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	this->Clear();
}

template<typename T>
const T& LinkedList<T>::operator[](unsigned int index) const
{
	if (index > count - 1)
	{
		throw out_of_range("Out of range!");
	}
	else
	{
		return (*this->GetNode(index)).data;
	}
}

template<typename T>
T& LinkedList<T>::operator[](unsigned int index)
{
	if (index > count - 1)
	{
		throw out_of_range("Out of range!");
	}
	else
	{
		return (*this->GetNode(index)).data;
	}
}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
	if (this->count != rhs.count)
	{
		return false;
	}
	else
	{
		unsigned int i = 0;
		Node* currptr = this->head;
		while(currptr != nullptr)
		{
			if ((*currptr).data != rhs[i])
			{
				return false;
			}
			currptr = (*currptr).next;
			i += 1;
		}
		return true;
	}
}

template<typename T>
void LinkedList<T>::PrintForward() const
{
	Node* currptr = this->head;
	while (currptr != nullptr)
	{
		cout <<  (*currptr).data << endl;
		currptr = (*currptr).next;
	}
}

template<typename T>
void LinkedList<T>::PrintReverse() const
{
	Node* currptr = this->tail;
	while (currptr != nullptr)
	{
		cout << (*currptr).data << endl;
		currptr = (*currptr).prev;
	}
}

template<typename T>
void LinkedList<T>::PrintForwardRecursive(const LinkedList<T>::Node* node) const
{
	cout << (*node).data << endl;
	if ((*node).next != nullptr)
	{
		this->PrintForwardRecursive((*node).next);
	}
}

template<typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const
{
	cout << (*node).data << endl;
	if ((*node).prev != nullptr)
	{
		this->PrintReverseRecursive((*node).prev);
	}
}

template<typename T>
unsigned int LinkedList<T>::NodeCount() const
{
	unsigned int cnt = 0;
	Node* currptr = this->head;
	while (currptr != nullptr)
	{
		cnt += 1;
		currptr = (*currptr).next;
	}
	return cnt;
}

template<typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const
{
	Node* currptr = this->head;
	while (currptr != nullptr)
	{
		if ((*currptr).data == value)
		{
			outData.push_back(currptr);
		}
		currptr = (*currptr).next;
	}
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const
{
	Node* currptr = this->head;
	while (currptr != nullptr)
	{
		if ((*currptr).data == data)
		{
			return currptr;
		}
		currptr = (*currptr).next;
	}
	return nullptr;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data)
{
	Node* currptr = this->head;
	while (currptr != nullptr)
	{
		if ((*currptr).data == data)
		{
			return currptr;
		}
		currptr = (*currptr).next;
	}
	return nullptr;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const
{
	unsigned int i = 0;
	Node* currptr = this->head;
	if (index > count - 1)
	{
		throw out_of_range("Out of range!");
	}
	while (currptr != nullptr)
	{
		if (i == index)
		{
			return currptr;
		}
		currptr = (*currptr).next;
		i += 1;
	}
	return nullptr;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
{
	unsigned int i = 0;
	Node* currptr = this->head;
	if (index > count - 1)
	{
		throw out_of_range("Out of range!");
	}
	while (currptr != nullptr)
	{
		if (i == index)
		{
			return currptr;
		}
		currptr = (*currptr).next;
		i += 1;
	}
	return nullptr;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	return this->head;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const
{
	return this->head;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail()
{
	return this->tail;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const
{
	return this->tail;
}

template<typename T>
void LinkedList<T>::AddHead(const T& data)
{
	if (this->head == nullptr)
	{
		this->head = new Node;
		(*this->head).data = data;
		this->tail = this->head;
		this->count += 1;
	}
	else
	{
		Node* newptr = new Node;
		(*newptr).next = this->head;
		(*newptr).data = data;
		(*this->head).prev = newptr;
		this->head = newptr;
		(*this->head).prev = nullptr;
		this->count += 1;
	}
}

template<typename T>
void LinkedList<T>::AddTail(const T& data)
{
	if (this->tail == nullptr)
	{
		this->tail = new Node;
		(*this->tail).data = data;
		this->head = this->tail;
		this->count += 1;
	}
	else
	{
		Node* newptr = new Node;
		(*newptr).prev = this->tail;
		(*newptr).data = data;
		(*this->tail).next = newptr;
		this->tail = newptr;
		(*this->tail).next = nullptr;
		this->count += 1;
	}
}

template<typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	int i = 0;
	for (i = count - 1; i >= 0; i--)
	{
		this->AddHead(data[i]);
	}
}

template<typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	unsigned int i = 0;
	for (i = 0; i <= count-1; i++)
	{
		this->AddTail(data[i]);
	}
}

template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data)
{
	Node* newptr = new Node;
	(*newptr).next = (*node).next;
	(*newptr).prev = node;
	(*newptr).data = data;
	(*node).next = newptr;
	(*node->next).prev = newptr;
	this->count += 1;
}

template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data)
{
	Node* newptr = new Node;
	(*newptr).next = node;
	(*newptr).prev = (*node).prev;
	(*newptr).data = data;
	(*node->prev).next = newptr;
	(*node).prev = newptr;
	this->count += 1;
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{
	unsigned int i = 0;
	if (index > this->count)
	{
		throw out_of_range("Out of range!");
	}
	for (i = 0; i <= index; i++)
	{
		if (index == 0)
		{
			this->AddHead(data);
			break;
		}
		else if (i == (index -1))
		{
			this->InsertAfter(this->GetNode(i),data);
			break;
		}
		else if (i == count)
		{
			this->AddTail(data);
			break;
		}
	}
}

template <typename T>
bool LinkedList<T>::RemoveHead()
{
	if (this->count == 0)
	{
		this->head = nullptr;
		this->tail = nullptr;
		return false;
	}
	else
	{
		if(this->count == 1)
		{
			delete this->head;
			this->count -= 1;
			return true;
		}
		else
		{
			this->head = (*this->head).next;
			delete (*this->head).prev;
			(*this->head).prev = nullptr;
			this->count -= 1;
			return true;
		}
	}
}

template <typename T>
bool LinkedList<T>::RemoveTail()
{
	if (this->count == 0)
	{
		this->head = nullptr;
		this->tail = nullptr;
		return false;
	}
	else
	{
		if(this->count == 1)
		{
			delete this->tail;
			this->count -= 1;
			return true;
		}
		else
		{
			this->tail = (*this->tail).prev;
			delete (*this->tail).next;
			(*this->tail).next = nullptr;
			this->count -= 1;
			return true;
		}
	}
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data)
{
	vector<Node*> deldata;
	this->FindAll(deldata,data);
	unsigned int delcnt = deldata.size();
	unsigned int i;
	for(i = 0; i<deldata.size(); i++)
	{
		(*deldata.at(i)->prev).next = (*deldata.at(i)).next;
		(*deldata.at(i)->next).prev = (*deldata.at(i)).prev;
		this->count -= 1;
		delete deldata.at(i);
	}
	return delcnt;
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index)
{
	try
	{
		unsigned int i = 0;
		if (index > this->count)
		{
			throw out_of_range("Out of range!");
		}
		for (i = 0; i <= index; i++)
		{
			if (index == 0)
			{
				this->RemoveHead();
				return true;
			}
			else if (i == index)
			{
				Node* currptr = this->GetNode(i);
				(*currptr->prev).next = (*currptr).next;
				(*currptr->next).prev = (*currptr).prev;
				delete currptr;
				this->count -= 1;
				return true;
			}	
			else if (i == count)
			{
				this->RemoveTail();
				return true;
			}
		}
		return false;
	}
	catch (out_of_range const&)
	{
		return false;
	}
}

template <typename T>
void LinkedList<T>::Clear()
{
	if (this->count != 0)
	{
		Node* currptr = this->head;
		Node* nextptr = (*currptr).next;
		while (nextptr != nullptr)
		{
			delete currptr;
			currptr = nextptr;
			nextptr = (*nextptr).next;
		}
		delete currptr;
		this->count = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}
}