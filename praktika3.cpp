// std::initialisations_list
// int a[]={0,1,2}
// std::vector<int> v = {0,1,2}
// в <algotithm> std::max({1,2,3})

// 1 реализовать для своего вектора
// 2 реализовать struct Vector3d{double x,y,z; 1,2,3} };

#include <initializer_list>
#include <iostream>

struct Vector3d {
private:
	double m_x, m_y, m_z;
	double m_data[3];
public:
	Vector3d(const std::initializer_list<double>& other) {
		int count = 0;
		for (auto it = other.begin(); it != other.end(); ++it) {
			m_data[count] = *it;
			count++;
		}
		std::cout << "1" << std::endl;
	}
	Vector3d& operator=(const std::initializer_list<double>& other) {
		int count = 0;
		for (auto it = other.begin(); it != other.end(); ++it) {
			m_data[count] = *it;
			count++;
		}
		std::cout << "2" << std::endl;
		return *this;

	}
	friend std::ostream& operator<< (std::ostream& out, const Vector3d& other) {
		out << "(";
		for (int count = 0; count < 3; count++)
			out << other.m_data[count] << "  ";
		out << ")" << std::endl;
		return out;
	}
};

int main() {

	//std::initializer_list<double> vector = { 1,2,3 };
	Vector3d v1( { 1, 2, 3 });
	std::cout << v1;
	Vector3d v2 = v1;
	std::cout << v2;
	return 0;
}




template <class T>
class VectorArr {
	T* m_data{ nullptr };
	int m_size{ 0 };
	int m_capacity{ 0 };

public:
	VectorArr() {
		m_data = 0;
		m_size = 0;
		m_capacity = 0;
	}
	VectorArr(int capacity) :
		m_capacity(capacity) {
		m_size = 0;
		m_data = new T[capacity];
		for (int count = 0; count < m_capacity; count++)
			m_data[count] = 0;
	}
	VectorArr(const VectorArr& other) {
		resize(other.m_size);
		m_data = new double[m_capacity];
	
		for (int count = 0; count < m_size; count++)
			m_data[count] = other.m_data[count];
	}
	VectorArr(const std::initializer_list<T>& other) {
		resize(other.size());
		m_data = new T[m_capacity];
		int count = 0;
		for (auto it = other.begin(); it != other.end(); ++it) {
			m_data[count] = *it;
			count++;
		}
	}
	~VectorArr() {
		m_size = 0;
		m_capacity = 0;
		delete[] m_data;
	}

	void resize(int newSize) {
		if (m_capacity > newSize)
			m_size = newSize;

		else {
			m_capacity = (newSize + 1) * 2;
			T* temp = new T[m_capacity];
			for (int count = 0; count < m_capacity; count++) {
				if (count < m_size)
					temp[count] = m_data[count];
				else
					temp[count] = 0;
			}
			m_size = newSize;
			delete[] m_data;
			m_data = temp;
		}
	}

	void pushback(T value) {
		if (m_capacity < m_size + 1)
			resize(m_size + 1);
		else
			m_size++;
		m_data[m_size - 1] = value;
	}

	T popback() {
		T temp = m_data[m_size];
		m_size--;
		return temp;
	}

	T erase(int index) {
		T temp = m_data[index];
		for (int count = index; count < m_size - 1; count++)
			m_data[count] = m_data[count + 1];
		m_size--;
		return temp;
	}

	void insert(T value, int index) {
		resize(m_size + 1);
		for (int count = m_size - 1; count > index; count--)
			m_data[count] = m_data[count - 1];
		m_data[index] = value;
	}

	VectorArr& operator=(const std::initializer_list<T>& other) {
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		m_data = new T[m_capacity];
		for (auto it = other.begin(); it != other.end(); ++it)
			m_data[it] = other.m_data[it];

		return *this;
	}
	VectorArr& operator=(const VectorArr& other) {
		if (&other == this)
			return *this;
		delete[] m_data;
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		m_data = new double[m_capacity];
		for (int count = 0; count < m_size; count++)
			m_data[count] = other.m_data[count];
	
		return *this;
	}

	friend std::ostream& operator<< (std::ostream& out, const VectorArr& other) {
		out << "(";
		for (int count = 0; count < other.m_size; count++)
			out << other.m_data[count] << "  ";
		out << ")" << std::endl;
		return out;
	}

	int getsize() {
		return m_size;
	}

};

int main() {
	VectorArr<int> vector= {1, 2, 3};
	std::cout << vector;
	vector.insert(5., 0);
	std::cout << vector;
	vector.insert(5., 0);
	std::cout << vector;
	vector.insert(5., 0);
	std::cout << vector;
	vector.insert(5., 0);
	std::cout << vector;
	return 0;
}
