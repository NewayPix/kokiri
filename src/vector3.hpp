#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

// TODO: Limit the instantiation types to numbers only.
template <class T>
class Vector3 {
public:
	T m_x;
	T m_y;
	T m_z;
public:
	Vector3(T x, T y, T z) {
		m_x = x;
		m_y = y;
		m_z = z;
	}

	~Vector3() {}

	Vector3<T> norm() {
		Vector3<T> normalized = *this;

		normalized.m_x /= mag();
		normalized.m_y /= mag();
		normalized.m_z /= mag();

		return normalized;
	}

	T mag() {
		return  sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
	}
};


#endif // VECTOR_H