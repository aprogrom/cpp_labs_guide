#include <iostream>
#include <string>

using namespace std;

void initialize_variables(){
    cout << "Initialize Variables" << endl;
    int a; // Объявление переменной
    int b = 0; // Объявление и инициализация в одной строке
    a = 1; // Инициализация ранее объявленной переменной
    int d, e; // Объявление нескольких переменных подряд в одной строке
    int f = 1, j = 4, l; // Объявление нескольких переменных с частичной инициализацией
    double k = 3.1; // Объявление и инциализация числа с плавающей запятой типа дабл
    float p = 3.2f; // Объявления и инициализация числа с плаваюшей запятой типа флоат
    char c = 'c'; // Объявление и инициализация символьной переменной
    string s = "string"; // Объявление и инициализация строки
    int arr[5]; // Объявление статического массива
    int iarr[5] = {1, 2, 3, 4, 5}; // Объявление и инициализация статического массива
}

void initialize_pointer(){
    int *pa; // объявление указателя
    int a = 0; // объявление и инициализация переменной
    pa = &a; // присвоение указателя на статической перемнной к ранее созданному указателю
    int *pb = new int(1); // присвоение к указателю памяти выделенной в куче с ее инициализацией
    int *pc = new int; // присвоение к указателю памяти выделенной в куче
    *pc = 1; // присвоение значения памяти скрытой за указателем
}


void initialize_link(){
    int a = 1; // Инициализация переменной
    int& la = a; // Объявление и инициализация ссылки на переменную(нельзя просто объявить)
}

void initialize_massive(){
    int ma[5]; // Объявление массива в статической памяти(локальная, стек)
    int mb[5] = {1, 2, 3, 4, 5}; // Объявление и инициализация массива в статической памяти(локальная, стек)
    int *pma = new int[5]; // Объявление массива в динамической памяти(куча)
    int *pmb = mb; // Создание указателя на статический массив(работает как обычный массив)
}

void ifelse_construction(){
    bool b = true;
    if(b){
        cout << "in if" << endl;
    }else{
        cout << "in else" << endl;
    }
}

void ifelseif_construction(){
    bool b = 1;
    bool f = 2;
    if(b*f % 10 > 1){
        cout << "in if" << endl;
    }else if(f < b){
        cout << "in else if" << endl;
    }else{
        cout << "in else" << endl;
    }
}

void readwrite_terminal(){
    int a = 10;
    string s = "string";
    bool b = true;
    double d = 3.22;
    cout << "All data here will be show in terminal: " << a << " " << s << " " << b << " " << d << endl;
    cin >> a;
    cout << "Data read and saved in variable: " << a << endl;
}

void cycle_for(){
    for(int i = 0; i < 10; i++){
        cout << i << endl;
    }
    int a[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }
    for(double k = 0; k < 10; k += 0.1){
        cout << k << endl;
    }
}

void cycle_while(){
    double p = 0;
    double h = 0.1;
    while(p < 10){
        p += h;
        cout << p << endl;
    }
    do{
        p -= h;
        cout << p << endl;
    }while(p > 0);
}

int main() {
    cycle_while();
    return 0;
}

