// COMSC-210 | Lab 20 | Christine Susic

#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;
const int MIN = 3, MAX = 4; //chair legs
const int MIN1 = 10000, MAX1 = 99999; //prices

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    //randomly select 3 or 4 legs
    //randomly select prices from 100.00 to 999.99
    Chair() {
        prices = new double[SIZE];
        legs = (rand() % (MAX-MIN+1) + MIN);
        for (int i = 0; i < SIZE; i++)
            double prices[i] = {(rand() % (MAX1-MIN1+1) + MIN1) / (double) 100};
    }
    //two parameters: the number of legs, 
    // and array of 3 doubles (the prices)
    Chair(int l, double[]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = 0;
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair;
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //default constructors used to populate these objects
    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    collection[i]
    //collection[1].setPrices();
    //collection[2].setPrices();
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}

