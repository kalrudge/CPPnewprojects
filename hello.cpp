#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <vector>
using namespace std;

vector<double> solver( double L, double N_x, int T_max, double dt, double D = 1.0, vector<double> inish_condish) {        
    double dx = L / (N_x - 1.0);
    double alpha = D * dt / (pow(dx,2));

    if (alpha > 0.5) {
         throw invalid_argument("Step size to large.");
    }
    vector<double> u = inish_condish;
    vector<double> u_next(N_x);

    int t_step = T_max / dt;

    for (int i = 0; i < t_step; i++){
        // Apply Boundary Conditions (Example: Fixed/Dirichlet boundaries)
        u_next[0] = u[0];
        u_next[N_x - 1] = u[N_x - 1];

        // Update interior points using central differences in space
        for (int j = 0; j < N_x-2; j++){
            u_next[j] = u[j] + alpha * (u[j+1] - 2*u[j] + u[j-1]);
        }
        u = u_next;
    }
    return u;
}



int main() {
    int age = 1;
    string name = "KA";
    cout << "The age is " << age << endl;
    cout << "The name is "<< name<< endl;
    cout << "Type in an age.";
    cin >> age;
    if (age >= 18){
        cout << "I am an adult."<< endl;}
    else {
        cout << "I am a child." << endl;}

    //std::cout << "My name is Kaleigh" << std::endl;
    
    return 0;
}