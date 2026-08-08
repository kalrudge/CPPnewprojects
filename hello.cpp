#include <iostream>
#include <string>

int main() {
    int age = 1;
    std::string name = "KA";
    std::cout << "The age is " << age <<std::endl;
    std:: cout << "The name is "<< name<<std::endl;
    std::cout << "Type in an age.";
    std::cin >> age;
    if (age >= 18){
        std::cout << "I am an adult."<< std::endl;}
    else {
        std::cout << "I am a child." << std::endl;}

    //std::cout << "My name is Kaleigh" << std::endl;
    
    return 0;
}