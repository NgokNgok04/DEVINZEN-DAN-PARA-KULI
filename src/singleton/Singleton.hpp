#include <bits/stdc++.h>
using namespace std;
//Design Pattern singleton ini untuk:
//1. Walikota
//2. GameManager
//3. Semua Parser
//Kenapa? Karena kedua objek ini instancenya cuma boleh ada satu, singleton ini mencegah
//buat bikin instance objek yang lebih dari satu

class Singleton {
    private:
        static Singleton* instances;
    protected:
        Singleton(){}
        ~Singleton(){}
        string valueTest;
    public:
        Singleton(Singleton &other) = delete;
        void operator=(const Singleton &) = delete;
        static Singleton *GetInstance(const string& value);
        string value() const{
            return valueTest;
        }
};
