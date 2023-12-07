#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class GPSCords{
    private:
    int latitude;
    int longitude;
    int elevation;

    public:
    GPSCords(int latitude, int longitude, int elevation){
        this->latitude = latitude;
        this->longitude = longitude;
        this->elevation = elevation;
    }

    int getLatitude() {return latitude;}
    int getLongitude() {return longitude;}
    int getElevation() {return elevation;}
    string toString() { return "GPS(" + to_string(getLatitude()) + ", " + to_string(getLongitude()) + ", " + to_string(getElevation()) + ")"; }
};

class Motor{
    private:
    int horsepower;
    int capacity;

    public:
    Motor(int horsepower, int capacity){
        this->horsepower = horsepower;
        this->capacity = capacity;
    }
    int getHorsePower() {return horsepower;}
    int getCapacity() {return capacity;}

    bool equals(Motor m2);
};

bool Motor::equals(Motor m2){
        return (this->horsepower == m2.getHorsePower() && this->capacity == m2.getCapacity());
}

/** EXERCISE #5 -- DEFINE A NEW Cordinable INTERFACE

 * Cordinable abstract class
 * Includes pure virtual methods to get and set Aircraft cords
 * More details below.
 */
class Cordinable{
    public:
        virtual GPSCords getCords() = 0;
        virtual void setCords(GPSCords c) = 0;
};

/** EXERCISE #3 -- COMPLETE Aircraft Figure CLASS
 *
 * Re-factor Aerostat and Plane classes.
 * An abstract class that holds the properties and implements the methods that are
 * common to existing Aerostat and Plane classes. All the moved properties must remain
 * PRIVATE and the moved methods PUBLIC. A method that is different in the subclasses
 * should be a pure virtual method in this abstract superclass and then defined in the
 * susbclassses, unless the methods behave equally in both subclasses.
 *
 * The abstract class should supply an appropriate constructor to be used by subclass
 * constructors to initialize the private properties defined in the abstract class.
 */
class Aircraft : public Cordinable{

    // YOUR CODE HERE
    private:
        string name;
        GPSCords cords;  

    public:
        Aircraft (string name, GPSCords cords): name(name), cords(cords) {}

        string getName() {return name;}
        //GPSCords getCords() {return cords;}
        GPSCords getCords();


        void setName(string n) {name = n;}
        //void setCords(GPSCords c) {cords = c;}
        void setCords(GPSCords c);



        virtual double getPressure(double temp) = 0;
        virtual double getLiftForce() = 0;

}; // End of abstract Aircraft class

GPSCords Aircraft::getCords(){
    // YOUR CODE HERE
    return cords;
}

void Aircraft::setCords(GPSCords c){
    // YOUR CODE HERE
    cords = c;
}

/**
 * Exercise #4 (Part A)
 * Re-factor this Aerostat class to remove any property or method that was
 * moved to the abstract Airplane class.  You should modify the
 * constructor to call the super constructor appropriately.
 *
 * This class represents Aerostat
 */

class Aerostat : public Aircraft{
    private:
        //string name;
        double volume;
        //GPSCords cords;

    public:
        //string getName() {return name;}
        double getVolume() {return volume;}
        //GPSCords getCords() {return cords;}

        Aerostat(string n, double vol, GPSCords c) : Aircraft(n, c), volume(vol)  {}

        // Instance methods

        // TODO EX #1 (Part A) -- Implement getPressure() in Aerostat class
        virtual double getPressure(double temp);

        // TODO EX #2 (Part A) -- Implement getLiftForce() in Aerostat class
        virtual double getLiftForce();
};

/**
 * Exercise #4 (Part B)
 * Re-factor this Plane class to remove any property or method that was
 * moved to the abstract Aircraft class.  You should modify the
 * constructor to call the super constructor appropriately.
 *
 * This class represents a Plane Aircraft
 *
 */

class Plane : public Aircraft{
    private:
        //string name;
        double length;
        double radius;
        //GPSCords cords;

    Motor m;        /////////////      <<=======

    public:
        //string getName() {return name;}
        double getLength() {return length;}
        double getRadius() {return radius;}
        //GPSCords getCords() {return cords;}

        Plane(string n, double ln, double r, GPSCords c): Aircraft (n, c), length(ln), radius(r), m(Motor(100,100)) {}

        // Instance methods

        // TODO EX #1 (Part A) -- Implement getPressure() in Plane class
        virtual double getPressure(double temp);

        // TODO EX #2 (Part A) -- Implement getLiftForce() in Plane class
        virtual double getLiftForce();
};

/**
 * EXERCISE #1 (Part A) -- Implement getPressure(double temp) in Aerostat class
 * 
 * HINT: The pressure for an ideal gas is (n * R * temp)/volume
 *      Assume that n * R = 0.32824
 */
double Aerostat::getPressure(double temp){
    // YOUR CODE HERE
    double pressure = (0.32824 * temp)/this->getVolume();
    return pressure;
}

/**
 * EXERCISE #2 (Part A) -- IMPLEMENT getLiftForce() method in Aerostat class.
 * 
 * HINT: Use Archimides' principle to calculate the lift force
 *      Force = -p * g * volume
 *      Asume that -p * g = -12.01725
 */
double Aerostat::getLiftForce(){
    // YOUR CODE HERE
    double force = -12.01725 * this->getVolume();
    return force;
}

/**
 * EXERCISE #1 (Part B) -- Implement getPressure(double temp) in Plane class
 * 
 * HINT: The pressure for an ideal gas is (n * R * temp)/volume
 *      Volume = π * radius * radius * length
 *      Assume that n * R = 0.32824
 *      Assume that π = 3.14159
 */
double Plane::getPressure(double temp){
    // YOUR CODE HERE
    double pressure = (0.32824 * temp) / (3.14159 * this->getRadius() * this->getRadius() * this->getLength());
    return pressure;
}

/**
 * EXERCISE #2 (Part B) -- IMPLEMENT getLiftForce() method in Plane class.
 * 
 * HINT: Lift Force = horsepower * capacity
 */
double Plane::getLiftForce(){
    // YOUR CODE HERE
    double force = m.getCapacity() * m.getCapacity();
    return force;
}



int main() {

    // Aerostat* a1 = new Aerostat("C1", 10, GPSCords(50, -40, 5000));
    // Aerostat* a2 = new Aerostat("C2", 20, GPSCords(70, -10, 1400));

    // Plane* p1 = new Plane("R1", 50, 5, GPSCords(30, -40, 15000));
    // Plane* p2 = new Plane("R2", 78, 8, GPSCords(-50, 90, 2500));

    // // Test Exercise #1
    // cout << "Aerostat(\"C1\", 10, GPSCords(50, -40, 5000)) pressure = " << a1->getPressure(50) << endl;
    // cout << "Aerostat(\"C2\", 20, GPSCords(70, -10, 1400)) pressure = " << a2->getPressure(30) << endl;
    // cout << "Plane(\"R1\", 50, 5, GPSCords(30, -40, 15000)) pressure = " << p1->getPressure(-10) << endl;
    // cout << "Plane(\"R2\", 78, 8, GPSCords(-50, 90, 2500)) pressure = " << p2->getPressure(0) << endl;
    // cout << "Aerostat(\"C1\", 10, GPSCords(50, -40, 5000)) lift force = " << a1->getLiftForce() << endl;
    // cout << "Aerostat(\"C2\", 20, GPSCords(70, -10, 1400)) lift force = " << a2->getLiftForce() << endl;
    // cout << "Plane(\"R1\", 50, 5, GPSCords(30, -40, 15000)) lift force = " << p1->getLiftForce() << endl;
    // cout << "Plane(\"R2\", 78, 8, GPSCords(-50, 90, 2500)) lift force = " << p2->getLiftForce() << endl;




    // Aerostat* a1 = new Aerostat("C1", 10, GPSCords(50, -40, 5000));
    // Aerostat* a2 = new Aerostat("C2", 20, GPSCords(70, -10, 1400));
    // Aerostat* a3 = new Aerostat("C3", 10, GPSCords(50, -40, 5000));
    // Aerostat* a4 = new Aerostat("C4", 20, GPSCords(70, -10, 1400));
    // Aerostat* a5 = new Aerostat("C5", 10, GPSCords(50, -40, 5000));

    // Plane* p1 = new Plane("R1", 50, 5, GPSCords(30, -40, 15000));
    // Plane* p2 = new Plane("R2", 78, 8, GPSCords(-50, 90, 2500));
    // Plane* p3 = new Plane("R3", 50, 5, GPSCords(30, -40, 15000));
    // Plane* p4 = new Plane("R4", 78, 8, GPSCords(-50, 90, 2500));
    // Plane* p5 = new Plane("R5", 50, 5, GPSCords(30, -40, 15000));

    // // Test Exercises #3 and #4
    // // This exercise will be graded mostly manually

    // vector<Aircraft*> aerostats{a1, a2, a3, a4, a5};
    // cout << "Aerostats: " << aerostats.size() << endl;

    // vector<Aircraft*> planes{p1, p2, p3, p4, p5};
    // cout << "Planes: " << planes.size() << endl;

    // vector<Aircraft*> aircrafts{a1, a2, a3, a4, a5, p1, p2, p3, p4, p5};
    // cout << "Aircrafts: " << aircrafts.size() << endl;



    Aerostat *c1 = new Aerostat ("C1", 500, GPSCords(1,9,200));
    Plane *r1 = new Plane ("R1", 10, 500, GPSCords(8,1,1000));

    GPSCords gp1(1,90,200);
    GPSCords gp2(8,10,1000);
    c1->setCords(gp2);
    cout << "C1 cords: " << c1->getCords().toString() << endl;
    r1->setCords(gp1);
    cout << "R1 cords: " << r1->getCords().toString() << endl;

}