#include <iostream>
#include <cmath>

using namespace std;

class Rational {
    private:
        int z;
        int n;
        int ggd(int x, int y);

    public:
        Rational() {
            z = 0;
            n = 1;
        }

        Rational(int p, int q) {
            z = p;
            n = q;

            this->simplify();
        }

        // Reduce as far as possible
        void simplify();

        // Overloading operators
        bool operator== (Rational arg);
        void operator= (Rational arg);
        Rational operator+ (Rational arg);
        void operator*= (Rational arg);

        // Need to make friend so ostream class can access private variables
        friend ostream& operator<<(ostream&, Rational);

        // Setter & Getter
        void set_z(int a);
        int get_z();

        void set_n(int b);
        int get_n();
};

void Rational::set_z(int a) {
    z = a;
}

int Rational::get_z() {
    return z;
}

void Rational::set_n(int a){
    n = a;
}

int Rational::get_n() {
    return n;
}

void Rational::simplify() {
    int tmp = ggd(z, n);
    
    z = z / tmp;
    n = n / tmp;
}

int Rational::ggd(int x, int y) {
    if (x == y)
        return x;

    else if (x > y) 
        return ggd(x - y, y);
    
    else 
        return ggd(y - x, x);
}

bool Rational::operator==(Rational arg) {
    // No need to use getter!
    return (this->z == arg.z) && (this->n == arg.n);
}

void Rational::operator=(Rational arg) {
    this->z = arg.z;
    this->n = arg.n;
}

Rational Rational::operator+(Rational arg) {
    int a = z * arg.n + arg.z * n;
    int b = n * arg.n;

    return Rational(a, b);
}


ostream& operator<< (ostream& os, Rational arg) {
    os << arg.z << '/' << arg.n << endl;
    return os;
}

void Rational::operator*=(Rational arg) {
    z *= arg.z;
    n *= arg.n;

    simplify();
}



int main() {
    Rational x(100, 20);
    Rational y(3, 5);
    Rational z(7, 3);

    cout << x.get_z() << "/" << x.get_n()<< endl;
    cout << y.get_z() << "/" << y.get_n()<< endl;

    x = y;

    cout << x.get_z() << "/" << x.get_n()<< endl;
    cout << y.get_z() << "/" << y.get_n()<< endl;

    cout << z.get_z() << "/" << z.get_n()<< endl;

    Rational m = z + y;

    cout << m.get_z() << "/" << m.get_n()<< endl;

    x *= y;

    cout << "---------\n";

    cout << x.get_z() << "/" << x.get_n()<< endl;

    cout << x << y << z;
}