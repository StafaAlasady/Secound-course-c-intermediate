#include <iostream>


int main(){
    int energydrink;
    bool EnergyinStock = true;

    std::cout << "Blue berry: 1\n";
    std::cout << "Raspberry: 2\n";
    std::cout << "Blue berry: 3\n";
    std::cout << "Colaflavored: 4\n";
    std::cout << "Enter the energydrink that you like: ";
    std::cin >> energydrink;


    
    if (EnergyinStock){
        std::cout << "We have energy drinks in house \n ";
    } else{
        std::cout << "The Energydrink stock is empty ";
    } 
}