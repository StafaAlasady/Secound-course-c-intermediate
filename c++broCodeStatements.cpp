#include<iostream>
#include <cmath>

int main (){
int age;

std::cout <<"Enter your age: ";
std::cin >> age;

if(age<18){

    std::cout << "Youre not allowed to enter and watch the distributed content, please leave gracefully "<< std::endl;

}

else{
        std::cout << "Welcome";
}

}