#include <iostream>
#include <cmath>

using namespace std;

class Boat{
private:
    float beam; // The width (ft) of the widest point of the boat
    float length; // The length (ft) of the boat
    float draft; // The max. sumerged (ft) depth of the boat
    int capacity; // The amount of people the boat can board
    float maxWeight; // The max. weight (lb) the boat can handle including people
    float milesPerGallon; // The motor's miles per galon rating when boat has max. weight

public:
    // Constructors
    /**
     * Default boat instance with given draft and miles per galon.
     * Beam = 3 ft
     * Lenght = 15 ft
     * Capacity = 3 people
     * Max. Weight = 500 lb
     */
    Boat(float dr, float mpg){
        beam = 3.0;
        length = 15.0;
        draft = dr;
        capacity = 3;
        maxWeight = 500.0;
        milesPerGallon = mpg;
    }

    // Constructor declared
    Boat(float beam, float length, float draft, int capacity, float maxWeight);

    // Getters
    float getBeam() const {return beam;}
    float getLength() const {return length;}
    float getDraft() const {return draft;}
    int   getCapacity() const {return capacity;}
    float getMaxWeight() const {return maxWeight;}
    float getMilesPerGalon() const {return milesPerGallon;}

    // Setters
    void setBeam(float beam) {this->beam = beam;}
    void setLenght(float length) {this->length = length;}
    void setCapacity(int capacity) {this->capacity = capacity;}
    void setMaxWeight(float maxWeight) {this->maxWeight = maxWeight;}

    // Tester Methods (DO NOT REMOVE)
    void printAttr(){
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << "Boat object: ";
        cout << "Beam: "; 
        cout << beam;
        cout << ", Length: ";
        cout << length;
        cout << ", Draft: ";
        cout << draft;
        cout << ", Capacity: ";
        cout << capacity;
        cout << ", Max. Weight: ";
        cout << maxWeight;
        cout << ", MPG: ";
        cout << milesPerGallon;
        cout << endl;
    }

    // Methods Declared
    bool  checkClearance(float waterDepth);
    bool  clearToSetSail(float luggage, int crewSize);
    void  increaseCapacity(int capacityToAdd);
    float calculateFuelCost(float fuelPrice, float distance);
    Boat  greatestCapacity(const Boat &b2);
    Boat  closeResized(float beam, float length);
    float getSalePrice();
    float motorPowerOutput(float degree);
    void  setDraft(float draft);
    void  setMilesPerGallon(float milesPerGalon);

};

int main(){
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);

    cout << "Welcome to Boat Class Tester!" << endl;
    cout << endl;
    cout << "EXERCISE #1 TESTER" << endl;
    Boat e1b1(3.0, 10.0, 2.0, 3, 400);
    Boat e1b2(7.0, 50.0, 3.0, 40, 2000);
    Boat e1b3(4.0, 20.0, 1.5, 10, 800);
    e1b1.printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 10.00, Draft: 2.00, Capacity: 3, Max. Weight: 400.00, MPG: 10.00
    e1b2.printAttr(); // EXPECTED: Boat object: Beam: 7.00, Length: 50.00, Draft: 3.00, Capacity: 40, Max. Weight: 2000.00, MPG: 10.00
    e1b3.printAttr(); // EXPECTED: Boat object: Beam: 4.00, Length: 20.00, Draft: 1.50, Capacity: 10, Max. Weight: 800.00, MPG: 10.00
    cout << endl;

    cout << "EXERCISE #2 TESTER" << endl;
    Boat e2b1(2.0, 10.0);
    Boat e2b2(3.0, 5.5);
    Boat e2b3(1.5, 8.75);
    cout << "Boat has clearance: ";
    cout << (e2b1.checkClearance(5.0) ? "true" : "false") << endl; // EXPECTED: Boat has clearance: true
    cout << "Boat has clearance: ";
    cout << (e2b2.checkClearance(5.0) ? "true" : "false") << endl; // EXPECTED: Boat has clearance: true
    cout << "Boat has clearance: ";
    cout << (e2b3.checkClearance(5.0) ? "true" : "false") << endl; // EXPECTED: Boat has clearance: true
    cout << "Boat has clearance: ";
    cout << (e2b1.checkClearance(2.0) ? "true" : "false") << endl; // EXPECTED: Boat has clearance: false
    cout << "Boat has clearance: ";
    cout << (e2b2.checkClearance(2.0) ? "true" : "false") << endl; // EXPECTED: Boat has clearance: false
    cout << "Boat has clearance: ";
    cout << (e2b3.checkClearance(2.0) ? "true" : "false") << endl; // EXPECTED: Boat has clearance: true
    cout << "Boat has clearance: ";
    cout << (e2b1.checkClearance(1.2) ? "true" : "false") << endl; // EXPECTED: Boat has clearance: false
    cout << "Boat has clearance: ";
    cout << (e2b2.checkClearance(1.2) ? "true" : "false") << endl; // EXPECTED: Boat has clearance: false
    cout << "Boat has clearance: ";
    cout << (e2b3.checkClearance(1.2) ? "true" : "false") << endl; // EXPECTED: Boat has clearance: false
    cout << endl;

    cout << "EXERCISE #3 TESTER" << endl;
    Boat e3b1(2.0, 10.0);
    cout << "Boat can set sail: ";
    cout << (e3b1.clearToSetSail(40, 4) ? "true" : "false") << endl; // EXPECTED: Boat can set sail: false
    cout << "Boat can set sail: ";
    cout << (e3b1.clearToSetSail(100, 3) ? "true" : "false") << endl; // EXPECTED: Boat can set sail: false
    cout << "Boat can set sail: ";
    cout << (e3b1.clearToSetSail(0, 3) ? "true" : "false") << endl; // EXPECTED: Boat can set sail: true
    e3b1.setCapacity(4);
    cout << "Boat can set sail: ";
    cout << (e3b1.clearToSetSail(40, 3) ? "true" : "false") << endl; // EXPECTED: Boat can set sail: true
    cout << "Boat can set sail: ";
    cout << (e3b1.clearToSetSail(50, 3) ? "true" : "false") << endl; // EXPECTED: Boat can set sail: false
    cout << "Boat can set sail: ";
    cout << (e3b1.clearToSetSail(250, 3) ? "true" : "false") << endl; // EXPECTED: Boat can set sail: false
    cout << endl;

    cout << "EXERCISE #4 TESTER" << endl;
    Boat e4b1(2.0, 10.0);
    e4b1.printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 3, Max. Weight: 500.00, MPG: 10.00
    e4b1.increaseCapacity(1);
    e4b1.printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 4, Max. Weight: 625.00, MPG: 10.00
    e4b1.increaseCapacity(0);
    e4b1.printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 4, Max. Weight: 625.00, MPG: 10.00
    e4b1.increaseCapacity(10);
    e4b1.printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 14, Max. Weight: 1875.00, MPG: 10.00
    cout << endl;

    cout << "EXERCISE #5 TESTER" << endl;
    Boat e5b1(2.0, 10.0);
    Boat e5b2(2.0, 5.0);
    cout << "Calculated Fuel: $";
    cout << e5b1.calculateFuelCost(2.5,100); // EXPECTED: Calculated Fuel: $25.00
    cout << endl << "Calculated Fuel: $"; 
    cout << e5b1.calculateFuelCost(1.0,50); // EXPECTED: Calculated Fuel: $5.00
    cout << endl << "Calculated Fuel: $"; 
    cout << e5b1.calculateFuelCost(1.5,0); // EXPECTED: Calculated Fuel: $0.00
    cout << endl << "Calculated Fuel: $";
    cout << e5b2.calculateFuelCost(2.5,100); // EXPECTED: Calculated Fuel: $50.00
    cout << endl << "Calculated Fuel: $"; 
    cout << e5b2.calculateFuelCost(1.0,50); // EXPECTED: Calculated Fuel: $10.00
    cout << endl << "Calculated Fuel: $"; 
    cout << e5b2.calculateFuelCost(1.5,0); // EXPECTED: Calculated Fuel: $0.00
    cout << endl;
    cout << endl;
    
    cout << "EXERCISE #6 TESTER" << endl;
    Boat e6b1(2.0, 10.0);
    Boat e6b2(4.0, 2.0);
    e6b1.greatestCapacity(e6b1).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 3, Max. Weight: 500.00, MPG: 10.00
    e6b1.greatestCapacity(e6b2).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 3, Max. Weight: 500.00, MPG: 10.00
    e6b2.greatestCapacity(e6b1).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 4.00, Capacity: 3, Max. Weight: 500.00, MPG: 2.00
    e6b2.greatestCapacity(e6b2).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 4.00, Capacity: 3, Max. Weight: 500.00, MPG: 2.00
    e6b1.setCapacity(10);
    e6b1.greatestCapacity(e6b1).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 10, Max. Weight: 500.00, MPG: 10.00
    e6b1.greatestCapacity(e6b2).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 10, Max. Weight: 500.00, MPG: 10.00
    e6b2.greatestCapacity(e6b1).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 10, Max. Weight: 500.00, MPG: 10.00
    e6b2.greatestCapacity(e6b2).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 4.00, Capacity: 3, Max. Weight: 500.00, MPG: 2.00
    e6b2.setCapacity(50);
    e6b1.greatestCapacity(e6b1).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 10, Max. Weight: 500.00, MPG: 10.00
    e6b1.greatestCapacity(e6b2).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 4.00, Capacity: 50, Max. Weight: 500.00, MPG: 2.00
    e6b2.greatestCapacity(e6b1).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 4.00, Capacity: 50, Max. Weight: 500.00, MPG: 2.00
    e6b2.greatestCapacity(e6b2).printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 4.00, Capacity: 50, Max. Weight: 500.00, MPG: 2.00
    cout << endl;

    cout << "EXERCISE #7 TESTER" << endl;
    Boat e7b1(2.0, 10.0);
    Boat e7b2(4.0, 2.0);
    e7b1.printAttr();                       // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 3, Max. Weight: 500.00, MPG: 10.00
    e7b1.closeResized(5,15).printAttr();    // EXPECTED: Boat object: Beam: 5.00, Length: 15.00, Draft: 2.00, Capacity: 5, Max. Weight: 850.00, MPG: 10.00
    e7b1.printAttr();                       // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 2.00, Capacity: 3, Max. Weight: 500.00, MPG: 10.00
    e7b2.printAttr();                       // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 4.00, Capacity: 3, Max. Weight: 500.00, MPG: 2.00
    e7b2.closeResized(10,75).printAttr();   // EXPECTED: Boat object: Beam: 10.00, Length: 75.00, Draft: 4.00, Capacity: 50, Max. Weight: 7600.00, MPG: 2.00
    e7b2.printAttr();                       // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 4.00, Capacity: 3, Max. Weight: 500.00, MPG: 2.00
    cout << endl;

    cout << "EXERCISE #8 TESTER" << endl;
    Boat e8b1(2.0, 10.0);
    Boat e8b2(2.0, 5.0);
    e8b2.setLenght(10);
    Boat e8b3(2.0, 5.0);
    e8b3.setLenght(35);
    Boat e8b4(2.0, 5.0);
    e8b4.setLenght(65);
    Boat e8b5(2.0, 5.0);
    e8b5.setLenght(90);
    Boat e8b6(2.0, 5.0);
    e8b6.setLenght(100);
    cout << "Boat selling price: $";
    cout << e8b1.getSalePrice(); // EXPECTED: Boat selling price: $33750.00
    cout << endl << "Boat selling price: $";
    cout << e8b2.getSalePrice(); // EXPECTED: Boat selling price: $10000.00
    cout << endl << "Boat selling price: $";
    cout << e8b3.getSalePrice(); // EXPECTED: Boat selling price: $78750.00
    cout << endl << "Boat selling price: $";
    cout << e8b4.getSalePrice(); // EXPECTED: Boat selling price: $146250.00
    cout << endl << "Boat selling price: $";
    cout << e8b5.getSalePrice(); // EXPECTED: Boat selling price: $202500.00
    cout << endl << "Boat selling price: $";
    cout << e8b6.getSalePrice(); // EXPECTED: Boat selling price: $225000.00
    cout << endl;
    cout << endl;

    cout << "EXERCISE #9 TESTER" << endl;
    Boat e10b1(2.0, 10.0);
    cout << "Motor power output percentage: ";
    cout << e10b1.motorPowerOutput(0.0); // EXPECTED: Motor power output percentage: 100.00
    cout << endl << "Motor power output percentage: ";
    cout << e10b1.motorPowerOutput(30.0); // EXPECTED: Motor power output percentage: 86.60
    cout << endl << "Motor power output percentage: ";
    cout << e10b1.motorPowerOutput(45.0); // EXPECTED: Motor power output percentage: 70.71
    cout << endl << "Motor power output percentage: ";
    cout << e10b1.motorPowerOutput(60.0); // EXPECTED: Motor power output percentage: 50.00
    cout << endl << "Motor power output percentage: ";
    cout << e10b1.motorPowerOutput(89.9); // EXPECTED: Motor power output percentage: 0.17
    cout << endl;
    cout << endl;


    cout << "EXERCISE #10 <<BONUS>> TESTER" << endl;
    cout << "IMPORTANT: To test the bonus exercises in VSCODE" << endl;
    cout << "     you must uncomment the code below this cout" << endl;
    cout << "     call (remove '/*' and '*/')" << endl;
    
    Boat e11b1(5.0, 8.0);
    e11b1.printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 5.00, Capacity: 3, Max. Weight: 500.00, MPG: 8.00
    e11b1.setDraft(3); 
    e11b1.printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 3.00, Capacity: 3, Max. Weight: 500.00, MPG: 8.00
    e11b1.setMilesPerGallon(10);
    e11b1.printAttr(); // EXPECTED: Boat object: Beam: 3.00, Length: 15.00, Draft: 3.00, Capacity: 3, Max. Weight: 500.00, MPG: 10.00
    
    
    return 0;
}

/**
 * EXERCISE #1
 * 
 * Implement a constructor that can be used to create a Boat object with
 * a specified beam measurement (ft), length measurement (ft),  
 * draft measurement (ft), people capacity, maximum weight (lb),
 * and a default 10.0 miles per galon.
 */
Boat::Boat(float beam, float length, float draft, int capacity, float maxWeight){
    // TODO -- YOUR CODE HERE
    this->beam = beam;
    this->length = length;
    this->draft = draft;
    this->capacity = capacity;
    this->maxWeight = maxWeight;
    this->milesPerGallon = 10.0;
}

/**
 * EXERCISE #2
 * 
 * Check if boat has enough clearance (more than) to navigate a specifided
 * water depth. Returns true if has clearance, otherwise returs false.
 * HINT: Look at the list of the class atributes and its comments.
 *   float beam; // The width (ft) of the widest point of the boat
 *   float length; // The length (ft) of the boat
 *   float draft; // The max. sumerged (ft) depth of the boat
 */
bool Boat::checkClearance(float waterDepth){
    // TODO -- YOUR CODE HERE
    if(waterDepth > this->getDraft()) {
        return true;
    }
    return false; // Dummy Return
}

/**
 * EXERCISE #3
 * 
 * Check if boat can set sail (maximum weight does not exceed the amount of
 * crew members and luggage weight combined or the amount of crew members 
 * exceeds the capacity) Assume that each crew member weights 150 pounds.
 */
bool Boat::clearToSetSail(float luggage, int crewSize){
    // TODO -- YOUR CODE HERE
    if((crewSize*150 + luggage) < this->getMaxWeight()  && crewSize <= this->getCapacity()) {
        return true;
    }
    return false; // Dummy Return
}

/**
 * EXERCISE #4
 * 
 * Increase boat capacity by given number or persons. Also increase the maximum weight of the 
 * boat assuming that each additional person weights 125 pounds.
 */
void Boat::increaseCapacity(int additionalPeople){
    // TODO -- YOUR CODE HERE
    capacity = this->getCapacity() + additionalPeople;
    maxWeight = this->getMaxWeight() + additionalPeople*125;
}

/**
 * EXERCISE #5
 * 
 * Returns the cost of the amount of fuel in gallons needed to navigate a 
 * given distance in miles. The fuel cost per galon is also given.
 * HINT: To calculate the price of the amount of fuel assume that the boat
 * is carrying the maximum weight.
 */
float Boat::calculateFuelCost(float fuelPrice, float distance){
    // TODO -- YOUR CODE HERE
    float cost = fuelPrice * distance / this->getMilesPerGalon();
    return cost; // Dummy Return
}

/**
 * EXERCISE #6
 * 
 * Returns the boat with the greatest capacity.
 * If both boats have the same capacity returns the target boat.
 */
Boat Boat::greatestCapacity(const Boat &b2){
    // TODO -- YOUR CODE HERE
    if(this->getCapacity() >= b2.getCapacity()) {
        return *this;
    } else {
        return b2;
    }
    //return nullptr; // Dummy return
}

/**
 * EXERCISE #7
 * 
 * Returns a new Boat object that has the same draft and miles per gallon
 * values as the target object. 
 * Assign the new parameter beam and length measurements to the new boat attributes.
 * By changing these attributes you need to calculate the new capacity
 * and maximum weight of the boat. Assume that the boat has a total capacity
 * of 100 pounds for luggage plus 150 pounds per crew mate.
 * HINT: To calculate the new capacity multiply both beam and length and
 * then divide that by 15.
 * HINT: Use the constructor that was already defined in the given code.
 */
// Boat Boat::closeResized(float beam, float length){
//     // TODO -- YOUR CODE HERE
//     float newbeam = beam;
//     float newlength = length;
//     float newdraft = this->getDraft();
//     int newcapacity = beam*length/15;
//     float newmaxWeight = this->getCapacity()*150 + 100;
//     return Boat(newbeam, newlength, newdraft, newcapacity, newmaxWeight);
// }
Boat Boat::closeResized(float beam, float length){
    // TODO -- YOUR CODE HERE
    Boat result(this->draft, this->milesPerGallon);
    result.setBeam(beam);
    result.setLenght(length);
    result.setCapacity(beam * length / 15);
    result.setMaxWeight(result.capacity*150 + 100);
    return result;
}
/**
 * EXERCISE #8
 * 
 * Returns the sale price of the boat as determied by its size as follows:
 * If the boat's length is less or equal than 10 ft the price is its length
 * times $1,000.00. Otherwise the price is its length times its beam times
 * $750.00.
 */
float Boat::getSalePrice(){
    // TODO -- YOUR CODE HERE
    float price;
    if(this->getLength() <= 10) {
        price = this->getLength() * 1000;
    } else {
        price = this->getLength() * this->getBeam() * 750;
    }
    return price; // Dummy Return
}

/**
 * EXERCISE #9
 * 
 * Returns the percentage of output power that the boat's
 * motor generates with a given angle. The angle is given 
 * as degree. Assume that at 0 degrees the motor propeller
 * is pointing parallel to the water surface.
 * 
 * Give that the propeller is directed at an angle of x degrees
 * the percent of output power can be calculated as the cos(x).
 * 
 * HINT: Use the C++ standard trigonometric functions to 
 * calculate the output power percentage. To get pi you can use
 * the inverse of the tangent of 1. (atan(1) = pi/4).
 * These functions do their calculations in radians, modifications
 * to the parameters may be needed. (radians * 180 / pi = degrees)
 */
float Boat::motorPowerOutput(float degree){
    // TODO -- YOUR CODE HERE
    float pi = atan(1)*4;
    float percentage = cos(degree * pi / 180) * 100; // times 100 bc its percentage
    return percentage; // Dummy Return
}

/**
 * EXERCISE #10 <<BONUS>>
 * 
 * Define the setters for draft, and milesPerGallon
 */
// TODO -- YOUR CODE HERE
void Boat::setDraft(float draft) {this->draft = draft;}
void Boat::setMilesPerGallon(float milesPerGallon) {this->milesPerGallon = milesPerGallon;}

