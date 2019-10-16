#include <iostream>


template <typename T> T* sort(T* mass, const int N){
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(mass[i] > mass[j]){
                T t = mass[i];
                mass[i] = mass[j];
                mass[j] = t;
            }
        }
    }
}


template <typename T> class Complex{
private:
    T Re = 0;
    T Im = 0;
public:
    Complex(T re, T im):Re(re),Im(im){};
    bool operator>(Complex b){
        return Re > b.Re;
    }
    T getRe(){
        return Re;
    }
    friend std::ostream& operator<<(std::ostream& stream, Complex<T> f){
        stream << f.Re;
        return stream;
    }
};

int main() {
    int a[5] = {5, 4, 4, 2, 7};
    double d[5] = {0.5, 0.4, 0.4, 0.2, 0.7};
    Complex<int> c[5] = {Complex<int>(0,1), Complex<int>(2.1,1), Complex<int>(4.4,1), Complex<int>(3.6,1), Complex<int>(-1.9,1)};
    sort<int>(a, 5);
    for( int i = 0; i < 5; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
    sort<double>(d, 5);
    for( int i = 0; i < 5; i++)
        std::cout << d[i] << ' ';
    std::cout << std::endl;
    sort<Complex<int>>(c, 5);
    for( int i = 0; i < 5; i++)
        std::cout << c[i].getRe() << ' ';
    std::cout << std::endl;
    Complex<Complex<int>> sc(Complex<int>(1.1, 1), Complex<int>(2.3, 1));
    std::cout << sc << std::endl;
    return 0;
}