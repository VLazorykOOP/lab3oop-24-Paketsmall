#include <iostream>
#include <string>
using namespace std;

class Matrix {
private:
    float* data;
    int rows;
    int columns;
    string errorCode;
public:
    Matrix()
        :data{ new float[4] }, rows{ 2 }, columns{ 2 }, errorCode{ 0 } {
        for (int i = 0; i < rows * columns; ++i) {
            data[i] = 0;
        }
    };
    Matrix(int n)
        :data{ new float[n * n] }, rows{ n }, columns{ n }, errorCode{ 0 } {
        for (int i = 0; i < rows * columns; ++i) {
            data[i] = 0;
        }
    };
    Matrix(int n, int m, float value)
        :data{ new float[n * m] }, rows{ n }, columns{ m }, errorCode{ 0 } {
        for (int i = 0; i < rows * columns; ++i) {
            data[i] = value;
        }
    }

    Matrix(const Matrix& other) : data(new float[other.rows * other.columns]), rows(other.rows), columns(other.columns), errorCode(other.errorCode) {
        for (int i = 0; i < rows * columns; ++i) {
            data[i] = other.data[i];
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            delete[] data;
            rows = other.rows;
            columns = other.columns;
            errorCode = other.errorCode;
            data = new float[rows * columns];
            for (int i = 0; i < rows * columns; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    ~Matrix() {
        delete[] data;
    }
    void assign(float value, int i = 0, int j = 0) {
        if (i + j <= rows + columns) {
            data[i + j] = value;
        }
    }
    float getElement(int i = 0, int j = 0) {
        if (i + j <= rows + columns) {
            return data[i + j];
        }
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << data[i + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void operator+(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Size are not match" << endl;
            return;
        }


        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << data[i + j] + other.data[i + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void operator*(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Size are not match" << endl;
            return;
        }


        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << data[i + j] * other.data[i + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void operator-(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Size are not match" << endl;
            return;
        }


        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << data[i + j] - other.data[i + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    bool operator==(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            return false;
        }

        for (int i = 0; i < rows * columns; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator>(const Matrix& other) const {
        return rows * columns > other.columns * other.rows;
    }
    bool operator<(const Matrix& other) const {
        return rows * columns < other.columns * other.rows;
    }


};

int main() {
    Matrix m1(3, 2, 5);
    Matrix m2(3, 3, 5);
    m1.print();
    m2.print();
    cout << "m2>m1: " << (m2 > m1) << endl;
    cout << "m2==m1: " << (m2 == m1) << endl;
    return 0;
}







#include <iostream>

using namespace std;

class Vec {
private:
    float* elements;
    int size;
public:
    Vec() {
        size = 1;
        elements = new float[size];
        elements[0] = 0;
    };
    Vec(int vecSize) {
        this->size = vecSize;
        elements = new float(size);
        for (int i = 0; i < size; ++i) {
            elements[i] = 0;
        }
    }
    Vec(int vecSize, float value) {
        this->size = vecSize;
        elements = new float[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = value;
        }
    }
    Vec(const Vec& other) {
        size = other.size;
        elements = new float[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    };
    Vec& operator=(const Vec& rhs) {
        if (this != &rhs) {
            delete[] elements;
            size = rhs.size;
            elements = new float[size];
            for (int i = 0; i < size; i++) {
                elements[i] = rhs.elements[i];
            }
        }
        return *this;
    }
    void setElement(int index, float value = 0) {
        if (index >= 0 && index < size) {
            elements[index] = value;
        }
    };
    float getElement(int index) {
        if (index >= 0 && index < size) {
            return elements[index];
        }
        return 0;
    }
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
    void operator+(long num) {
        for (int i = 0; i < size; i++) {
            elements[i] += num;
        }
    }
    void operator-(long num) {
        for (int i = 0; i < size; i++) {
            elements[i] -= num;
        }
    }
    void operator*(long num) {
        for (int i = 0; i < size; i++) {
            elements[i] *= num;
        }
    }
    bool operator==(const Vec& rhs) const {
        if (size != rhs.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (elements[i] != rhs.elements[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator>(const Vec& rhs) const {
        if (size > rhs.size) {
            return true;
        }
        return false;
    }
    bool operator<(const Vec& rhs) const {
        if (size < rhs.size) {
            return true;
        }
        return false;
    }
    ~Vec() {
        delete[] elements;
    }
};

int main() {
    Vec v1;
    Vec v2(3);
    Vec v3(3, 5);

    v1.print();
    v2.print();
    v3.print();

    cout << "v2>v3: " << (v2 > v3) << endl;
    cout << "v2 == v3: " << (v2 == v3) << endl;
    v2 = v3;
    cout << "v2 == v3: " << (v2 == v3) << endl;

    return 0;
}















#include <iostream>
#include <string>
using namespace std;

class Matrix {
private:
    float* data;
    int rows;
    int columns;
    string errorCode;
public:
    Matrix()
        :data{ new float[4] }, rows{ 2 }, columns{ 2 }, errorCode{ 0 } {
        for (int i = 0; i < rows * columns; ++i) {
            data[i] = 0;
        }
    };
    Matrix(int n)
        :data{ new float[n * n] }, rows{ n }, columns{ n }, errorCode{ 0 } {
        for (int i = 0; i < rows * columns; ++i) {
            data[i] = 0;
        }
    };
    Matrix(int n, int m, float value)
        :data{ new float[n * m] }, rows{ n }, columns{ m }, errorCode{ 0 } {
        for (int i = 0; i < rows * columns; ++i) {
            data[i] = value;
        }
    }

    Matrix(const Matrix& other) : data(new float[other.rows * other.columns]), rows(other.rows), columns(other.columns), errorCode(other.errorCode) {
        for (int i = 0; i < rows * columns; ++i) {
            data[i] = other.data[i];
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            delete[] data;
            rows = other.rows;
            columns = other.columns;
            errorCode = other.errorCode;
            data = new float[rows * columns];
            for (int i = 0; i < rows * columns; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    ~Matrix() {
        delete[] data;
    }
    void assign(float value, int i = 0, int j = 0) {
        if (i + j <= rows + columns) {
            data[i + j] = value;
        }
    }
    float getElement(int i = 0, int j = 0) {
        if (i + j <= rows + columns) {
            return data[i + j];
        }
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << data[i + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void operator+(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Size are not match" << endl;
            return;
        }


        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << data[i + j] + other.data[i + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void operator*(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Size are not match" << endl;
            return;
        }


        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << data[i + j] * other.data[i + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void operator-(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Size are not match" << endl;
            return;
        }


        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << data[i + j] - other.data[i + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    bool operator==(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            return false;
        }

        for (int i = 0; i < rows * columns; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator>(const Matrix& other) const {
        return rows * columns > other.columns * other.rows;
    }
    bool operator<(const Matrix& other) const {
        return rows * columns < other.columns * other.rows;
    }


};

int main() {
    Matrix m1(3, 2, 5);
    Matrix m2(3, 3, 5);
    m1.print();
    m2.print();
    cout << "m2>m1: " << (m2 > m1) << endl;
    cout << "m2==m1: " << (m2 == m1) << endl;
    return 0;
}












