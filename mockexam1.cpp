#include <cctype>
#include <iostream>
#include <string>
using namespace std;


/*

First Exam Practice!

Tips:

  - > Create your own test cases once you're done!
    - - > What would happen if for exercise #4 all of the 
          robots were friendly? What about if they were all 
          unfriendly? What happens when we fuse different robots?   
          Make unique cases!
    
  - > Create your own methods! Get creative.

*/

class Robot {
private:
  bool friendly;
  double powerLevel;
  string CPU;
  string name;

public:
  // Constructor
  Robot(bool f, double p, string cpu, string n) {
    this->friendly = f;
    this->powerLevel = p;
    this->CPU = cpu;
    this->name = n;
  }

  // Getters
  bool isFriendly() { return friendly; }
  double getPowerLevel() { return powerLevel; }
  string getCPU() { return CPU; }
  string getName() { return name; }

  // Setters
  void setFriend(bool friendly) { this->friendly = friendly; }
  void setPowerLevel(double powerLevel) { this->powerLevel = powerLevel; }
  void setCPU(string CPU) { this->CPU = CPU; }
  void setName(string name) { this->name = name; }

  // Methods
  bool canBeFriends(Robot);
  bool canHandle(Robot);
  string isFirstRobot();
  Robot createFusedRobot(Robot, Robot);
};

// #1
bool Robot::canBeFriends(Robot strangerRobot) {
  /*
  -> This method checks if two robots can be friends!
        -> If they are both friendly, return true
        -> Otherwise, false.
  */
  if (this->friendly && strangerRobot.isFriendly()) {
      return true;
    } else {
        return false;
    } 
}

// #2
bool Robot::canHandle(Robot opponent) {
  /*
  -> This method checks if the target robot can fight and win
      against the parameter robot (compare power levels)
        -> If target has a bigger or equal power level, return true
        -> Otherwise, false
  */
  if (this->powerLevel >= opponent.getPowerLevel()) {
    return true;
  } else {
    return false;
  } // dummy return
}


// #3
string Robot::isFirstRobot() {
  /*
  
  Robots are created and have a serial number.
  Here are some examples of possible robot names:

  "0-R2D2"
  "1-R2D2"
  "2-R2D2"

  -> If a robot is a first of it's kind (Serial number starts with 0) return
  "FIRST".
  -> If a robot doesn't have a serial number, return "UNKNOWN"
  -> Otherwise, return "NOTFIRST"

  */
  if (name[0] == '0') {
    return "FIRST";
  } else if (isdigit(name[0])) {
    return "NOTFIRST";
  } else {
  return "UNKNOWN";
  } // dummy return
}

// #4
Robot Robot::createFusedRobot(Robot robotOne, Robot robotTwo) {
  /*

  Create and return a new robot. Read all specs before writing solution!
  This robot must:
  A.  Have the last two characters of
      the target robot, the first parameter robot and the second parameter
      robot (in that order) as its name, joined by the symbol "-".
          Example, if we have:
          this->getName() = "1-Luffy"
          other1.getName() = "2-Zoro"
          other2.getName() = "3-Sanji"
        The name of the fusion between each should be: "fy-ro-ji"
  B. Its powerLevel must be the sum of all the power levels. If they all have
      extra compatability (same powerLevel), they get a 20% bonus
      on top of the summed power levels. For every friendly robot fused,
      they get a 10% increase in powerLevel. For every unfriendly robot,
      they get a 10% decrease in powerLevel. 
          Example: If we happened to fuse two friendly robots 
          and one unfriendly, all with the same power level,
          we'd have a 30% bonus (20% + 10% + 10% - 10%)
        If we had three unfriendly robots with different
        power levels, we'd have a 30% decrease (-10% + -10% + -10%)
  C. It will be unfriendly by default.
  D. Its processor will be that of the strongest robot. If they all
     have the same power level, the fusion will use the processor of
     the target robot.
  */

    // NAME
    string lastTwoCharsThis = this->getName().substr(this->getName().length() - 2);
    string lastTwoCharsRobotOne = robotOne.getName().substr(robotOne.getName().length() - 2);
    string lastTwoCharsRobotTwo = robotTwo.getName().substr(robotTwo.getName().length() - 2);
      string fusedName = lastTwoCharsThis + "-" + lastTwoCharsRobotOne + "-" + lastTwoCharsRobotTwo;
    
    // POWER LEVEL
    double pLevelThis = this->getPowerLevel();
    double pLevelROne = robotOne.getPowerLevel();
    double pLevelRTwo = robotTwo.getPowerLevel();
    double totalpLevel = pLevelThis + pLevelROne + pLevelRTwo;
    double r0p = totalpLevel * 0.10;
    double r1p = totalpLevel * 0.10;
    double r2p = totalpLevel * 0.10;

    if (pLevelThis == pLevelROne && pLevelThis == pLevelRTwo) {
        totalpLevel = totalpLevel + (totalpLevel * 0.20);
    } else {
        totalpLevel = totalpLevel;
    }

    if (this->friendly) {
        r0p = r0p;
    } else {
        r0p = -r0p;
    }

    if (robotOne.isFriendly()) {
        r1p = r1p;
    } else {
        r1p = -r1p;
    }

    if (robotTwo.isFriendly()) {
        r2p = r2p;
    } else {
        r2p = -r2p;
    }

    totalpLevel = totalpLevel + r0p + r1p + r2p;

    double biggest;
    if (this->getPowerLevel() >= robotOne.getPowerLevel()) {
        biggest = this->getPowerLevel();
        CPU = this->getCPU();
        //setCPU(this->getCPU());
    } else {
        biggest = robotOne.getPowerLevel();
        CPU = robotOne.getCPU();
    }

    if (biggest >= robotTwo.getPowerLevel()) {
        biggest = biggest;
    } else {
        biggest = robotTwo.getPowerLevel();
        CPU = robotTwo.getCPU();
    }

    Robot fusedRobot(false, totalpLevel, CPU, fusedName);
    return fusedRobot;
    
}

int main() {
  // Test cases
  Robot r1 = Robot(true, 8000, "Ryzen", "0-Frankie");
  Robot r2 = Robot(false, 8000, "Ryzen", "0-Zoro");
  Robot r3 = Robot(false, 8000, "Ryzen", "3-Sanji");
  Robot r4 = Robot(true, 20000, "Intel", "0-Luffy");
  Robot r5 = Robot(true, 10, "Potato", "Chopper");
  Robot r6 = Robot(false, 1000000, "Ryzen", "Usopp");
  
  // cout << "Can r1 be friends with each robot?" << endl;
  // cout << "r2: " << (r1.canBeFriends(r2) ? "true" : "false") << endl;
  // cout << "r3: " << (r1.canBeFriends(r3) ? "true" : "false") << endl;
  // cout << "r4: " << (r1.canBeFriends(r4) ? "true" : "false") << endl;
  // cout << "r5: " << (r1.canBeFriends(r5) ? "true" : "false") << endl;
  // cout << "r6: " << (r1.canBeFriends(r6) ? "true" : "false") << endl;

  // EXERCISE 1
  cout << "\n EXERCISE 1: \n" << endl;
  cout << r1.canBeFriends(r4) << endl; // 1
  cout << r2.canBeFriends(r3) << endl; // 0

  // EXERCISE 2
  cout << "\n EXERCISE 2: \n" << endl;
  cout << r6.canHandle(r4) << endl; // 1
  cout << r1.canHandle(r3) << endl; // 1
  cout << r5.canHandle(r6) << endl; // 0

  // EXERCISE 3
  cout << "\n EXERCISE 3: \n" << endl;
  cout << r1.isFirstRobot() << endl; // "FIRST"
  cout << r5.isFirstRobot() << endl; // "UNKNOWN"
  cout << r3.isFirstRobot() << endl; // "NOTFIRST"
  
  // EXERCISE 4
  cout << "\n EXERCISE 4: \n" << endl;
  Robot fuse1 = r1.createFusedRobot(r2, r3);
  Robot fuse2 = r4.createFusedRobot(r5, r6);

  cout << fuse1.isFriendly() << endl; // false
  cout << fuse1.getPowerLevel() << endl; // 26400
  cout << fuse1.getCPU() << endl; // Ryzen
  cout << fuse1.getName() << endl; // ie-ro-ji

  cout << fuse2.isFriendly() << endl; // false
  cout << fuse2.getPowerLevel() << endl; // 1122012
  cout << fuse2.getCPU() << endl; // Ryzen
  cout << fuse2.getName() << endl; // fy-er-pp
  

  return 0;
}