#include <iostream>
#include <initializer_list>

#define size_t int

template <class T>
class List {
	struct Node {
		T m_elem = T(); // элемент 
		Node* m_next = nullptr; // указатель на следующий элемент
		Node(T elem, Node* next) : m_elem(elem), m_next(next) {}
		Node(T elem) : m_elem(elem) {}
		Node() {}
	};
	Node* m_first = nullptr;
public:
	List() {}
	//explicit List(const size_t size) {
	//	for (size_t count = 0; count < size; ++count) {
	//		m_first = new Node();
	//	
	//	}
	//}
	List(size_t size,T elem) {
		if (size == 0)
			return;
		m_first = new Node(elem);
		Node* temp = m_first;
		for (size_t count = 0; count < size; count++) {
			temp->m_next = new Node(elem);
			temp = temp->m_next;
		}
	}

	size_t size() {
		Node* temp = m_first;
		size_t count = 0;
		//temp = temp->m_next;
		while (temp) {
			//if (temp->m_next == nullptr)
			//	return count;
			count++;
			temp = temp->m_next;
		}
		return count;
	}

	void print() {
		Node* temp = m_first;
		//temp = temp->m_next;
		while (temp) {
			//if (temp->m_next == nullptr)
			//	break;
			std::cout << temp->m_elem << "\t";
			temp = temp->m_next;
		}
	}
};

int main() {

	List<int> list(9,2);
	list.print();
	
	std::cout << list.size() << std::endl;
	return 0;
}