#include <stdio.h>

struct A{
    private:
        int x;
    public: 
        int y;
    A(){
        printf("Object Created!\n");
    }
};

int main(){
    struct A a;
}