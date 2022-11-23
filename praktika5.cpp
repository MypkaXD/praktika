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
		Node(const Node& other) {
			m_elem = other.m_elem;
			delete[] m_next;
			m_next = new Node();
			m_next = other.m_next;
		}
	};
	Node* m_first = nullptr;
public:
	List() {}
	explicit List(const size_t size) {
		if (size == 0)
			return;
		if (size < 0)
			throw ("ERROR: SIZE SHOULD BE GRERATER THAN ZERO");
		m_first = new Node();
		Node* temp = m_first;
		for (size_t count = 1; count < size; ++count) {
			temp->m_next = new Node();
			temp = temp->m_next;
		}
	}
	//List(const T elem) {
	//	m_first = new Node(elem);
	//	Node* temp = m_first;
	//}
	List(size_t size,T elem) {
		if (size == 0)
			return;
		m_first = new Node(elem);
		Node* temp = m_first;
		for (size_t count = 1; count < size; count++) {
			temp->m_next = new Node(elem);
			temp = temp->m_next;
		}
	}
	List(const List<T>& other) {
		delete[] m_first;
		m_first = new Node(other.m_first->m_elem);
		Node* temp = m_first;
		for (size_t count = 1; count < other.size(); count++) { // есть ли другой способ? типо for (size_t count = 1; other.m_first->m_next!=nullptr; count++)???
			temp->m_next = new Node(other.m_first->m_elem);
			temp = temp->m_next;
		}
	}
	List(const std::initializer_list<T>& list) {
		delete[] m_first;
		m_first = new Node(*list.begin());
		Node* temp = m_first;
		for (auto it = list.begin() + 1; it < list.end(); ++it) {
			temp->m_next = new Node(*it);
			temp = temp->m_next;
		}
	}

	const size_t size() const noexcept{
		Node* temp = m_first;
		size_t count = 0;
		while (temp) {
			temp = temp->m_next;
			count++;
		}
		return count;
	}

	void print() {
		Node* temp = m_first;
		while (temp) {
			std::cout << temp->m_elem << "\t";
			temp = temp->m_next;
		}
	}
};

int main() {

	List<int> list1(10,2);
	list1.print();
	
	std::cout << list1.size() << std::endl;

	List<int> list2(14);
	list2.print();
	std::cout << list2.size() << std::endl;

	List<int> list3(list1);
	list3.print();
	std::cout << list3.size() << std::endl;

	List<int> list4({ 1,2,3 });
	list4.print();
	std::cout << list4.size() << std::endl;
	return 0;
}
