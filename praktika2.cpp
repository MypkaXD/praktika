/*
пишем класс

template <class T>
class Vector{
	private:
		T *data = nullptr;
		int n= 0;
	public:
		Конструктор Vector() = default;
		Констрктор с параметром Vector(int m_n): n(m_n) data (new int[n]){} // std::cout << "Вызван конструктор с параметром" << std::endl;
		Конструктор копирования (const // std::cout << "Вызван конструктор копирования" << std::endl;
		Vector& operator=(const Vector& other); // Опертор =; return *this; рассмотреть a = a; std::cout << "Вызван опертор =" << std::endl;
		Деструктор ~Vector(){delete[] data;}
		
};
*/

#include <iostream>


template <class T>
class Vector {
private:
	int m_n = 0;
	T* m_data = nullptr;
public:
	Vector() = default;
	Vector(int n)
		: m_n(n), m_data(new T[m_n]) {
		std::cout << "Вызван конструктор с параметром" << std::endl;
	}
	Vector(const Vector& other){
		m_n = other.m_n;
		m_data = new T[m_n];
		for (int count = 0; count < m_n; count++) {
			m_data[count] = other.m_data[count];
		}
		std::cout << "Вызван конструктор копирования" << std::endl;
	}
	Vector& operator=(const Vector& other) {
		std::cout << "Вызван опертор =" << std::endl;
		if (other.m_data == this->m_data) {
			return *this;
		}
		m_n = other.m_n;
		m_data = new int[m_n];
		for (int count = 0; count < m_n; count++) {
			m_data[count] = other.m_data[count];
		}
		return *this;
	}

	int getSize() const{
		return m_n;
	}

	~Vector() { 
		std::cout << "Вызван деструктор" << std::endl;
		delete[] m_data; 
	}

	Vector(Vector&& other) noexcept {
		this->m_n = other.m_n;
		this->m_data = other.m_data;//move
		other.m_data = nullptr;
		other.m_n = 0;
		//std::swap(other.m_data, this->m_data);
		//std::swap(other.m_n, this->m_n);
		std::cout << "Конструктор перемещения" << std::endl;
	}

	Vector& operator=(Vector&& other) {// операторт перемещения
		if (this == &other) {
			return *this;
		}
			delete[] this->m_data;
			this->m_data = other.m_data;
			this->m_n = other.m_n;
			other.m_data = nullptr;
			other.m_n = 0;
			std::cout << "Вызван операторт перемещения" << std::endl;
			return *this;
	}
};

int main() {
	setlocale(LC_ALL, "rus");

	Vector<int> v6;
	std::cout << v6.getSize() << std::endl;
	Vector <int> v7(v6);
	v7 = v6;
	std::cout << v7.getSize() << std::endl;
	return 0;
}

/*


Vector <int> v = Vector<int>(10);// создаем временыый объект, move, не удалился
Vector<int> v2;
Vector<int> v3 = v2;
//семантик перемещение, как во втроой лабе

*/