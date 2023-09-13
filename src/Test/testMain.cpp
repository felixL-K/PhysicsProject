#include "../PhysicLib/Vector2D.hpp"

int main() {
    Vector2D v{1,2};
    v.add(v);
    std::cout << v << std::endl;
    double neg;
    int nbNEG = 0;
    int nbPOS = 0;
    for(int i = 0; i<1000; i++){
        neg = (double)rand() / RAND_MAX;
        cout << neg << endl;
        if(neg<0.5) {
            nbNEG++;
        } else {
            nbPOS++;
        }
    }
    cout << "neg : " << nbNEG << endl;
    cout << "pos : " << nbPOS << endl;
}