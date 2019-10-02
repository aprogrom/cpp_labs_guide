#include <iostream>
#include <stdlib.h>

using namespace std;

class Worker{
private:
    double wage = 0;
    double eff = 0;
public:
    Worker(double wage):wage(wage){
        eff = 0.5 + (double)rand() / (double)RAND_MAX * 2;
    }
    virtual void work(){
        cout << "I am Worker" << endl;
    }
    void eat(){
        cout << "I am eat" << endl;
    }
    double getEff(){
        return eff / 2;
    }
    void setWage(double wage){
        this->wage = wage;
    }
};


class Frontend: public Worker{
public:
    Frontend(double wage):Worker(wage){}
    void work(){
        cout << "I am Frontend" << endl;
    }
};

class Backend: public Worker{
public:
    Backend(double wage):Worker(wage){}
    void work(){
        cout << "I am Backend" << endl;
    }
};

class Projecter: public Worker{
public:
    Projecter(double wage):Worker(wage){}
    void work(){
        cout << "I am Projecter" << endl;
    }
};

class Designer: public Worker{
public:
    Designer(double wage):Worker(wage){}
    void work(){
        cout << "I am Designer" << endl;
    }
};

class Manager: public Worker{
public:
    Manager(double wage):Worker(wage){}
    void work(){
        cout << "I am Manager, iam not work" << endl;
    }
};


class DevelopmentDepartment{
private:
    Worker** employeers;
    int count_employeers = 0;
    Worker* createWorker(int type, double wage){
        switch (type){
            case 1:
                return new Frontend(wage);
                break;
            case 2:
                return new Backend(wage);
                break;
            case 3:
                return new Projecter(wage);
                break;
            case 4:
                return new Designer(wage);
                break;
            case 5:
                return new Manager(wage);
                break;
            default:
                return new Worker(wage);
        }
    }

public:
    DevelopmentDepartment(const int N):count_employeers(N){
        employeers = new Worker*[N];
        for(int i = 0; i < N; i++){
            int type = 1 + rand() % 5;
            double wage = rand() % 100000;
            employeers[i] = createWorker(type, wage);
        }
    }
    void work(){
        for(int i = 0; i < count_employeers; i++)
            employeers[i]->work();
    }
    void diner(){
        for(int i = 0; i < count_employeers; i++)
            employeers[i]->eat();
    }
    double summEff(){
        double summ = 0;
        for(int i = 0; i < count_employeers; i++)
            summ += employeers[i]->getEff();
        return summ / count_employeers;
    }
    ~DevelopmentDepartment(){
        delete employeers;
    }
};


int main() {
    int N = 0;
    cin >> N;
    DevelopmentDepartment d(N);
    for(int i = 0; i < 9; i++) {
        if (i == 4)
            d.diner();
        d.work();
    }
    cout << d.summEff() << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}