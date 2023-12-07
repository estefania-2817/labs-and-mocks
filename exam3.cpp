#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// Enumeration to represent different shape types.
enum ShapeType {
    CIRCLE, COLORED_CIRCLE,
    TRIANGLE, SIERPINSKI_TRIANGLE,
    UNDEFINED
};

/* ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 *                                             *
 *                 Shape Class                 *
 *                                             *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ */
class Shape {
public:

    // Print the information of the shape.
    virtual void PrintInfo() const = 0;
    
    /* ******************** *
     * EXCERCISE PROBLEM #2 *
     * ******************** */
    virtual ShapeType GetShapeType() = 0;
    static int CountShapes(vector<Shape*>& shapes, ShapeType targetType, int index) ;

    /* ******************** *
     * EXCERCISE PROBLEM #5 *
     * ******************** */
    virtual void Scale(double factor) = 0;
    static void ScaleShapes(vector<Shape*> shapes, double factor) ;

    /* ******************** *
     * EXCERCISE PROBLEM #7 *
     * ******************** */
    virtual double CalculateArea() const = 0;
    static double CalculateTotalArea(vector<Shape*> shapes) ;

    /* ******************** *
    * EXCERCISE PROBLEM #8 *
    * ******************** */
    virtual double CalculatePerimeter() const = 0;
    bool ComparePerimeter(const Shape& other) const ;

};

/* ******************** *
* EXCERCISE PROBLEM #2 *
* ******************** */
// TODO: 
//  Define the method called CountShapes(shapes,targetType,index) 
//  in the abstract class Shape that will count the number of shapes of a specific 
//  targetType in the vector shapes starting at a given index.
// IMPORTANT: Your answer MUST be RECURSIVE and MUST call the virtual method GetShapeType()
// to obtain the type of shape of each object in the vector.
// Do not use loops in the CountShapes(shapes,targetType,index) method. 
// Do not create a helper function.
int Shape::CountShapes(vector<Shape*>& shapes, ShapeType targetType, int index) {
    // YOUR CODE HERE
    if(shapes.size() == index) {
        return 0;
    }
    if(shapes[index]->GetShapeType() == targetType) {
        return 1 + CountShapes(shapes, targetType, index + 1); 
    } else {
        return 0 + CountShapes(shapes, targetType, index + 1); 
    }
}

/* ******************** *
* EXCERCISE PROBLEM #5 *
* ******************** */
// TODO:
// Define the method called ScaleShapes(shapes, factor) for the abstract class Shape 
// that will scale all the shapes in the vector shapes by the given factor using the 
// virtual method Scale().
void Shape::ScaleShapes(vector<Shape*> shapes, double factor) {
    // YOUR CODE HERE
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->Scale(factor);
    }
}

/* ******************** *
* EXCERCISE PROBLEM #7 *
* ******************** */
// TODO:
// Create a method called CalculateTotalArea(shapes) for the Abstract class Shape
// that will calculate the sum of areas of all shapes in the vector shapes using 
// the virtual method CalculateArea().
double Shape::CalculateTotalArea(vector<Shape*> shapes) {
    // YOUR CODE HERE
    int totalArea = 0;
    for(int i = 0; i < shapes.size(); i++) {
        totalArea = totalArea + shapes[i]->CalculateArea();
    }
    return totalArea; //Dummy Return
}


/* ******************** *
* EXCERCISE PROBLEM #8 *
* ******************** */
// TODO:
// Compares the perimeter of two shapes by calling the CalculatePerimeter() virtual method 
// from all subclasses.
// Returns true if the first shape's perimeter is less than the second shape' perimeter.
bool Shape::ComparePerimeter(const Shape& other) const {
    // YOUR CODE HERE
    return !false; //Dummy Return
}

/* ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 *                                             *
 *                Circle Class                 *
 *                                             *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ */
class Circle : public Shape {
private:
    double center[2];
    double radius;

public:
    // Constructor
    Circle(double x, double y, double r) {
        center[0] = x; 
        center[1] = y; 
        radius = r;
    }
    

    // setters
    void setCenterX(double x) { center[0] = x;};
    void setCenterY(double y) { center[1] = y;};
    void setRadius(double r) { radius = r;};
    
    // getters
    double getCenterX() const {return center[0];};
    double getCenterY() const {return center[1];};
    double getRadius() const {return radius;};

    // Print the information of a circle.
    void PrintInfo() const {
        cout << "Circle(" << getCenterX() << ", " << getCenterY() << ", "
                << getRadius() << ")" << endl; 
    }

    /* ******************** *
     * EXCERCISE PROBLEM #1 *
     * ******************** */
    Circle(double r);
    
    /* ******************** *
     * EXCERCISE PROBLEM #2 *
     * ******************** */
    ShapeType GetShapeType()  ;

    /* ******************** *
     * EXCERCISE PROBLEM #3 *
     * ******************** */
    bool Overlaps(const Circle& other) const ;

    /* ******************** *
     * EXCERCISE PROBLEM #5 *
     * ******************** */
    virtual void Scale(double factor) ;

    /* ******************** *
     * EXCERCISE PROBLEM #6 *
     * ******************** */
    bool Equals(const Circle& other) ;

    /* ******************** *
     * EXCERCISE PROBLEM #7 *
     * ******************** */
    double CalculateArea() const  ;
    
    /* ******************** *
    * EXCERCISE PROBLEM #8 *
    * ******************** */
    double CalculatePerimeter() const ;

};


/* ******************** *
* EXCERCISE PROBLEM #1 *
* ******************** */
// TODO: 
// Create a new constructor the Circle class Circle(r)
// where the default center is (0.0, 0.0) and the radius is 
// given by the r parameter.
Circle::Circle(double r){
    // YOUR CODE HERE
    center[0] = 0; 
    center[1] = 0; 
    radius = r;
}

/* ******************** *
* EXCERCISE PROBLEM #2 *
* ******************** */
// TODO: Create the virtual method GetShapeType() in the Shape subclass Circle.
ShapeType Circle::GetShapeType() {
    // YOUR CODE HERE
    return CIRCLE; //Dummy Return
}

/* ******************** *
* EXCERCISE PROBLEM #3 *
* ******************** */
// TODO: 
// Create a method called Overlaps for the Circle Class. 
// This method will compare two circles and will return true if they overlap.
bool Circle::Overlaps(const Circle& other) const {
    // YOUR CODE HERE
    int x1 = this->getCenterX();
    int x2 = other.getCenterX();
    int y1 = this->getCenterX();
    int y2 = other.getCenterY();
    int distance = sqrt( ((x1-x2)*(x1-x2) + ((y1-y2)*(y1-y2))) );
    int sumR = this->getRadius() + other.getRadius();
    if (distance <= sumR) {
        return true;
    } else {
        return false; //Dummy Return
    }
}

/* ******************** *
* EXCERCISE PROBLEM #5 *
* ******************** */
// TODO:
// Create the virtual method Scale(factor) for the Shape subclass Circle.
void Circle::Scale(double factor) {
    // YOUR CODE HERE
    radius = this->getRadius() * factor;
}

 /* ******************** *
* EXCERCISE PROBLEM #6 *
* ******************** */
// TODO: 
// Create a method called Equals for for the Shape subclass Circle. 
// This method will compare two Circles and will return true if they have the same dimensions.
bool Circle::Equals(const Circle& other) {
    // YOUR CODE HERE
    if(this->getRadius() == other.getRadius()) {
        return true;
    } else {
        return false; //Dummy Return
    }
}

/* ******************** *
* EXCERCISE PROBLEM #7 *
* ******************** */
// TODO:
// Create the virtual method CalculateArea() for the Shape subclasses Circle.
double Circle::CalculateArea() const  {
    // YOUR CODE HERE
    double area = this->getRadius() * this->getRadius() * M_PI;
    return area; //Dummy Return
}

/* ******************** *
* EXCERCISE PROBLEM #8 *
* ******************** */
// TODO:
// Create the virtual method CalculatePerimeter() for the Shape subclasses Circle.
double Circle::CalculatePerimeter() const  {
    // YOUR CODE HERE
    return 0.0; //Dummy Return
}

/* ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 *                                             *
 *            ColoredCircle Class              *
 *                                             *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ */
class ColoredCircle : public Circle {
private:
    string color;
public:
    // Constructor
    ColoredCircle(double x, double y, double r, string c): Circle(x,y,r) {
        color = c;
    } 

    // setters
    void setColor(string c) { color = c;};
    
    // getters
    string getColor() const {return color;};

    // Print the information of a colored circle.
    void PrintInfo() const {
        cout << "ColoredCircle(" << getCenterX() << ", " << getCenterY() << ", "
                << getRadius() << ", " << getColor() << ")" << endl; 
    }

    /* ******************** *
     * EXCERCISE PROBLEM #1 *
     * ******************** */
    ColoredCircle(double r, string c); 

    /* ******************** *
     * EXCERCISE PROBLEM #2 *
     * ******************** */
    ShapeType GetShapeType()  ;

};

/* ******************** *
* EXCERCISE PROBLEM #1 *
* ******************** */
// TODO: 
// Create a new constructor for the ColoredCircle class ColoredCircle(r, c)
// where the default center is (0.0, 0.0) and the side and color are 
// given by the s and c parameters.
ColoredCircle::ColoredCircle(double r, string c) : Circle(0, 0, r) {
    // YOUR CODE HERE 
    color = c;
}

/* ******************** *
* EXCERCISE PROBLEM #2 *
* ******************** */
// TODO: 
// Create the virtual method GetShapeType() in the Shape subclass ColoredCircle. 
ShapeType ColoredCircle::GetShapeType()  {
    // YOUR CODE HERE
    return COLORED_CIRCLE; //Dummy Return
}


/* ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 *                                             *
 *               Triangle Class                *
 *                                             *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ */
class Triangle : public Shape {
private:
    double sides[3];

public:
    // Constructor
    Triangle(double a, double b, double c){sides[0] = a; sides[1] = b;sides[2] = c;}
    
    // setters
    void setSide1(double s) { sides[0] = s; }
    void setSide2(double s) { sides[1] = s; }
    void setSide3(double s) { sides[2] = s; }

    // getters
    double getSide1() const { return sides[0]; }
    double getSide2() const { return sides[1]; }
    double getSide3() const { return sides[2]; }
   
    // Print the information of a triangle.
    void PrintInfo() const {
        cout << "Triangle(" << getSide1() << ", " << getSide2() << ", "
                << getSide3() << ")" << endl; 
    }

    /* ******************** *
     * EXCERCISE PROBLEM #2 *
     * ******************** */
    ShapeType GetShapeType()  ;

    /* ******************** *
     * EXCERCISE PROBLEM #4 *
     * ******************** */
    vector<double> CalculateAngles() const ;

    /* ******************** *
    * EXCERCISE PROBLEM #5 *
    * ******************** */
     virtual void Scale(double factor) ;

    /* ******************** *
     * EXCERCISE PROBLEM #6 *
     * ******************** */
    bool Equals(const Triangle& other) ;

    /* ******************** *
    * EXCERCISE PROBLEM #7 *
    * ******************** */
    double CalculateArea() const  ;

    /* ******************** *
    * EXCERCISE PROBLEM #8 *
    * ******************** */
    double CalculatePerimeter() const ;
};

/* ******************** *
* EXCERCISE PROBLEM #2 *
* ******************** */
// TODO: 
// Create the virtual method GetShapeType() in the Shape subclass Triangle.
ShapeType Triangle::GetShapeType()  {
    // YOUR CODE HERE
    return TRIANGLE; //Dummy Return
}

/* ******************** *
* EXCERCISE PROBLEM #4 *
* ******************** */
// TODO: 
// Create a method called CalculateAngles for the Triangle Class. This method will calculate all
// the angles of a triangle given its sides, the method returns a vector with the three angles.
// Use the given formula (Law of Cosines).
vector<double> Triangle::CalculateAngles() const {
   // YOUR CODE HERE
    double s1 = this->getSide1();
    double s2 = this->getSide2();
    double s3 = this->getSide3();
    double angleA = acos( ((s2 * s2) + (s3* s3) - (s1 * s1)) / (2 * s2 * s3));
    double angleB = acos( ((s1 * s1) + (s3* s3) - (s2 * s2)) / (2 * s1 * s3));
    double angleC = M_PI - angleA - angleB; 
    return {angleA, angleB, angleC}; //Dummy Return
}

/* ******************** *
* EXCERCISE PROBLEM #5 *
* ******************** */
// TODO:
// Create the virtual method Scale(factor) for the Shape subclass Triangle.
void Triangle::Scale(double factor) {
    // YOUR CODE HERE
    sides[0] = this->getSide1() * factor;
    sides[1] = this->getSide2() * factor;
    sides[2] = this->getSide3() * factor;
}

/* ******************** *
* EXCERCISE PROBLEM #6 *
* ******************** */
// TODO: 
// Create a method called Equals for for the Shape subclass Triangle. 
// This method will compare two Triangles and will return true if they have the same dimensions.
bool Triangle::Equals(const Triangle& other) {
    // YOUR CODE HERE
    if(this->getSide1() == other.getSide1() && this->getSide2() == other.getSide2() && this->getSide3() == other.getSide3()) {
        return true;
    } else {
        return false; //Dummy Return
    }
}

/* ******************** *
* EXCERCISE PROBLEM #7 *
* ******************** */
// TODO:
// Create the virtual method CalculateArea() for the Shape subclasses Triangle.
double Triangle::CalculateArea() const  {
    // YOUR CODE HERE
    double s1 = this->getSide1();
    double s2 = this->getSide2();
    double s3 = this->getSide3();
    double s = (s1 + s2 + s3) / 2;
    double area = sqrt( s * (s-s1) * (s-s2) * (s-s3) );
    return area; //Dummy Return
}

/* ******************** *
* EXCERCISE PROBLEM #8 *
* ******************** */
// TODO:
// CalculatePerimeter()
//      Create the virtual method CalculatePerimeter() for the Shape subclasses Triangle.
double Triangle::CalculatePerimeter() const {
    // YOUR CODE HERE
    return 0.0; //Dummy Return
}

/* ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 *                                             *
 *         Sierpinski Triangle Class           *
 *                                             *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ */
class SierpinskiTriangle : public Triangle {
private:
    int iterations ; 
public:
    // Constructor
    SierpinskiTriangle(double a, int b) : Triangle(a, a, a) {iterations = b;}

    // setters
    void setIterations(int i) { iterations = i; }

    // getters
    int getIterations() const { return iterations; }

    // Print the information of a sierpinski triangle.
    void PrintInfo() const {
        cout << "SierpinskiTriangle(" << getSide1() << ", " << getIterations() << ")" << endl; 
    }

    /* ******************** *
     * EXCERCISE PROBLEM #2 *
     * ******************** */
    ShapeType GetShapeType()  ;

    /* ******************** *
    * EXCERCISE PROBLEM #6 *
    * ******************** */
    bool Equals(const SierpinskiTriangle& other) ;

    /* ******************** *
     * EXCERCISE PROBLEM #7 *
     * ******************** */
    double CalculateAreaHelper (int iterations, double sideLength) const ;
    double CalculateArea() const  ;

    /* ******************** *
    * EXCERCISE PROBLEM #8 *
    * ******************** */
    double CalculatePerimeterHelper (int iterations, double sideLength) const ;
    double CalculatePerimeter() const  ;
    
};

/* ******************** *
* EXCERCISE PROBLEM #2 *
* ******************** */
// TODO: 
// Create the virtual method GetShapeType() in the Shape subclass SierpinskiTriangle.
ShapeType SierpinskiTriangle::GetShapeType()  {
    // YOUR CODE HERE
    return SIERPINSKI_TRIANGLE; //Dummy Return
}

/* ******************** *
* EXCERCISE PROBLEM #6 *
* ******************** */
// TODO: 
// Create a method called Equals for for the Shape subclass SierpinskiTriangle. 
// This method will compare two Sierpinski Triangles and will return true if they have the same dimensions.
bool SierpinskiTriangle::Equals(const SierpinskiTriangle& other) {
    // YOUR CODE HERE
    if(this->getSide1() == other.getSide1() && this->getSide2() == other.getSide2() && this->getSide3() == other.getSide3()) {
        return true;
    } else {
        return false; //Dummy Return
    }
}


/* ******************** *
* EXCERCISE PROBLEM #7 *
* ******************** */
// TODO:
// CalculateArea()
//      Create the virtual method CalculateArea() for the Shape subclasses SierpinskiTriangle.
// CalculateAreaHelper(iterations, sideLength)
//      For the SierpinskiTriangle subclass create the method 
//      CalculateAreaHelper(iterations, sideLength)
//      that receives as parameter the iterations and side length 
//      to calculate recursively the area of a SierpinskiTriangle .

double SierpinskiTriangle::CalculateAreaHelper(int iterations, double sideLength) const {
    // YOUR CODE HERE
    if(this->getIterations() == iterations) {
        return 0;
    }
    if(iterations = 0) {
        return sqrt(3) / 4 * sideLength * sideLength;
    } else {
        return 3 * CalculateAreaHelper(iterations + 1, sideLength/2);
    }
}
double SierpinskiTriangle::CalculateArea() const  {
    // YOUR CODE HERE
    return CalculateAreaHelper(0, this->getSide1()); //Dummy Return
}

// double SierpinskiTriangle::CalculateAreaHelper(int iterations, double sideLength) const {
//     if (iterations == 0) {
//         // Base case: Area of an equilateral triangle = (sqrt(3) / 4) * sideLength^2
//         return (sqrt(3.0) / 4.0) * sideLength * sideLength;
//     } else {
//         // Recursive case: Divide the triangle into three smaller triangles
//         double smallerSideLength = sideLength / 2.0;
//         double smallerArea = CalculateAreaHelper(iterations - 1, smallerSideLength);

//         // Total area is the sum of three identical smaller triangles
//         return 3.0 * smallerArea;
//     }
// }

// double SierpinskiTriangle::CalculateArea() const  {
//     // Assuming some default values for iterations and side length,
//     // you might want to adjust these based on your requirements.


//     return CalculateAreaHelper(this->getIterations(), this->getSide1());
// }

/* ******************** *
* EXCERCISE PROBLEM #8 *
* ******************** */
// TODO:
// CalculatePerimeter()
//      Create the virtual method CalculatePerimeter() for the Shape subclasses SierpinskiTriangle.
// CalculatePerimeterHelper(iterations, sideLength)
//      For the SierpinskiTriangle subclass create the method 
//      CalculatePerimeterHelper(iterations, sideLength)
//      that receives as parameter the iterations and side length 
//      to calculate recursively the perimeter of a SierpinskiTriangle.
double SierpinskiTriangle::CalculatePerimeterHelper(int iterations, double sideLength) const {
    // YOUR CODE HERE
    return -1.0; //Dummy Return
}
double SierpinskiTriangle::CalculatePerimeter() const {
    // YOUR CODE HERE
    return 0.0; //Dummy Return
}



/* ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 *                                             *
 *                TEST CASES                   *
 *                                             *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ *
 * ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ ~*~ */
int main(){

    /*
    * 
    * EXCERCISE PROBLEM #1
    * uncomment for testing
    * 
    */

    // vector<Shape*> shapes;
    // shapes.push_back( new Circle(2.5) );
    // shapes.push_back( new ColoredCircle(1.0, "red") );
    // shapes.push_back( new ColoredCircle(5.0, 1.0, 1.0, "red") );
    // shapes.push_back( new Circle(3.0, 5.0, 1.0) );
    // shapes.push_back( new Circle(5.0) );

    // for (int i= 0; i < shapes.size(); i++) {
    //     (*shapes[i]).PrintInfo();
    // }
    // cout << endl;


    /*
    * 
    * EXCERCISE PROBLEM #2
    * uncomment for testing
    * 
    */

    // vector<Shape*> shapes;
    // shapes.push_back( new Circle(5.0, 0.0, 2.5) );
    // shapes.push_back( new ColoredCircle(0.0, 0.0, 1.0, "red") );
    // shapes.push_back( new Triangle(3.0, 4.0, 5.0) );
    // shapes.push_back( new SierpinskiTriangle(1.0, 4) );
    // shapes.push_back( new Triangle(3.0, 3.0, 3.0) );
    // shapes.push_back( new ColoredCircle(0.0, 0.0, 1.0, "red") );
    // shapes.push_back( new SierpinskiTriangle(3.0, 2) );
    // shapes.push_back( new Circle(0.0, 0.0, 1.0) );
    // shapes.push_back( new Triangle(1.0,1.0,2.0) );
    // shapes.push_back( new Circle(0.5, 2.0, 5.0) );

    // // Count the number of circles using the CountShapes method.
    // cout << "Number of circles: " << Shape::CountShapes(shapes, CIRCLE, 0) << endl;
    // // Count the number of colored circles using the CountShapes method.
    // cout << "Number of colored circles: " << Shape::CountShapes(shapes, COLORED_CIRCLE, 0) << endl;
    // // Count the number of triangles using the CountShapes method.
    // cout << "Number of triangles: " << Shape::CountShapes(shapes, TRIANGLE, 0) << endl;
    // // Count the number of sierpinski triangle using the CountShapes method.
    // cout << "Number of sierpinski triangle: " << Shape::CountShapes(shapes, SIERPINSKI_TRIANGLE, 0) << endl;
    

   /*
    * 
    * EXCERCISE PROBLEM #3
    * uncomment for testing
    * 
    */
   
    // Circle circle1(0.0, 0.0, 1.0) ;
    // Circle circle2(4.0, 3.0, 1.0) ;
    // Circle circle3(0.0, 0.0, 2.0) ;
    // Circle circle4(3.0, 4.0, 2.0) ;

    // cout << boolalpha ;

    // cout << circle1.Overlaps(circle1) << endl; 
    // cout << circle1.Overlaps(circle2) << endl;  
    // cout << circle1.Overlaps(circle3) << endl;   
    // cout << circle1.Overlaps(circle4) << endl;  
    // cout << circle2.Overlaps(circle2) << endl;  
    // cout << circle2.Overlaps(circle3) << endl;   
    // cout << circle2.Overlaps(circle4) << endl;  
    // cout << circle3.Overlaps(circle3) << endl;   
    // cout << circle3.Overlaps(circle4) << endl;  
    // cout << circle4.Overlaps(circle4) << endl;  

    /*
    * 
    * EXCERCISE PROBLEM #4
    * uncomment for testing
    * 
    */
    
    // Triangle triangle1(3.0, 4.0, 5.0) ;
    // Triangle triangle2(3.0, 4.0, 5.0) ;
    // Triangle triangle3(4.0, 4.0, 4.0) ;
    // Triangle triangle4(5.0, 4.0, 5.0) ;

    // vector<double> angles;
    // angles = triangle1.CalculateAngles(); 
    // cout << "Angles: " << to_string(angles[0]) << "," << to_string(angles[1]) << "," << to_string(angles[2]) << endl; 
    // angles = triangle2.CalculateAngles(); 
    // cout << "Angles: " << to_string(angles[0]) << "," << to_string(angles[1]) << "," << to_string(angles[2]) << endl;
    // angles = triangle3.CalculateAngles(); 
    // cout << "Angles: " << to_string(angles[0]) << "," << to_string(angles[1]) << "," << to_string(angles[2]) << endl;
    // angles = triangle4.CalculateAngles(); 
    // cout << "Angles: " << to_string(angles[0]) << "," << to_string(angles[1]) << "," << to_string(angles[2]) << endl;


    /*
    * 
    * EXCERCISE PROBLEM #5
    * uncomment for testing
    * 
    */
   
    // vector<Shape*> shapes;
    // shapes.push_back( new Circle(5.0, 0.0, 2.5) );
    // shapes.push_back( new ColoredCircle(0.0, 0.0, 1.0, "red") );
    // shapes.push_back( new Triangle(3.0, 4.0, 5.0) );
    // shapes.push_back( new SierpinskiTriangle(1.0, 4) );
    // shapes.push_back( new Triangle(3.0, 3.0, 3.0) );
    // shapes.push_back( new ColoredCircle(0.0, 0.0, 1.0, "red") );
    // shapes.push_back( new SierpinskiTriangle(3.0, 2) );
    // shapes.push_back( new Circle(0.0, 0.0, 1.0) );
    // shapes.push_back( new Triangle(1.0,1.0,2.0) );
    // shapes.push_back( new Circle(0.5, 2.0, 5.0) );

    // cout << "Shape Info before scale by 4: " << endl; 
    // for (int i= 0; i < shapes.size(); i++) {
    //     (*shapes[i]).PrintInfo();
    // }
    // cout << endl;
    // Shape::ScaleShapes(shapes, 4);
    // cout << "Shape Info after scale by 4: " << endl; 
    // for (int i= 0; i < shapes.size(); i++) {
    //     (*shapes[i]).PrintInfo();
    // }
    // cout << endl;


    /*
    * 
    * EXCERCISE PROBLEM #6
    * uncomment for testing
    * 
    */

    Circle circle1(0.0, 0.0, 1.0) ;
    Circle circle2(4.0, 3.0, 1.0) ;
    Triangle triangle1(3.0, 4.0, 5.0) ;
    Triangle triangle2(3.0, 4.0, 5.0) ;
    ColoredCircle red1(0.0, 0.0, 1.0, "red") ;
    ColoredCircle red2(4.0, 3.0, 1.0, "red") ;
    SierpinskiTriangle sierpinski1(3.0, 1) ;
    SierpinskiTriangle sierpinski2(3.0, 2) ;

    cout << boolalpha ;
    cout << circle1.Equals(circle2) << endl;  
    cout << triangle1.Equals(triangle2) << endl;
    cout << red2.Equals(red2) << endl;
    cout << sierpinski1.Equals(sierpinski2) << endl;  

    // true
    // true
    // true
    // false

   /*
    * 
    * EXCERCISE PROBLEM #7
    * uncomment for testing
    * 
    */

    // vector<Shape*> shapes;
    // shapes.push_back( new Circle(5.0, 0.0, 2.5) );
    // shapes.push_back( new ColoredCircle(0.0, 0.0, 1.0, "red") );
    // shapes.push_back( new Triangle(3.0, 4.0, 5.0) );
    // shapes.push_back( new Triangle(3.0, 3.0, 3.0) );
    // shapes.push_back( new ColoredCircle(0.0, 0.0, 1.0, "red") );
    // shapes.push_back( new Circle(0.0, 0.0, 1.0) );
    // shapes.push_back( new Triangle(1.0,1.0,2.0) );
    // shapes.push_back( new Circle(0.5, 2.0, 5.0) );

    // double totalArea = Shape::CalculateTotalArea(shapes);
    // cout << "Total Area of Shapes: " << totalArea << endl; 
    
    /*
    * 
    * EXCERCISE PROBLEM #7
    * uncomment for testing
    * 
    */

    // vector<Shape*> shapes;
    // shapes.push_back( new Circle(5.0, 0.0, 2.5) );
    // shapes.push_back( new ColoredCircle(0.0, 0.0, 1.0, "red") );
    // shapes.push_back( new Triangle(3.0, 4.0, 5.0) );
    // shapes.push_back( new SierpinskiTriangle(1.0, 4) );
    // shapes.push_back( new Triangle(3.0, 3.0, 3.0) );
    // shapes.push_back( new ColoredCircle(0.0, 0.0, 1.0, "red") );
    // shapes.push_back( new SierpinskiTriangle(3.0, 2) );
    // shapes.push_back( new Circle(0.0, 0.0, 1.0) );
    // shapes.push_back( new Triangle(1.0,1.0,2.0) );
    // shapes.push_back( new Circle(0.5, 2.0, 5.0) );

    // double totalArea = Shape::CalculateTotalArea(shapes);
    // cout << "Total Area of Shapes: " << totalArea << endl; 
    // 17.935
    

    /*
    * 
    * EXCERCISE PROBLEM #8
    * uncomment for testing
    * 
    */

    // Circle circle(5.0, 0.0, 2.5);
    // ColoredCircle redCircle(0.0, 0.0, 1.0, "red");
    // Triangle triangle(3.0, 4.0, 5.0);
    // SierpinskiTriangle sierpinski(1.0, 4);

    // cout << boolalpha ;
    // cout << circle.ComparePerimeter(triangle) << endl; 
    // cout <<  redCircle.ComparePerimeter(sierpinski) << endl; 

    /*
    * 
    * EXCERCISE PROBLEM #8
    * uncomment for testing
    * 
    */

    // Circle circle(5.0, 0.0, 2.5);
    // ColoredCircle redCircle(0.0, 0.0, 1.0, "red");
    // Triangle triangle(3.0, 4.0, 5.0);
    // SierpinskiTriangle sierpinski(1.0, 4);

    // cout << boolalpha ;
    // cout << redCircle.ComparePerimeter(sierpinski) << endl;
    // cout << triangle.ComparePerimeter(circle) << endl; 
    // cout << sierpinski.ComparePerimeter(redCircle) << endl; 

    //true
    //false


    return 0;
}


