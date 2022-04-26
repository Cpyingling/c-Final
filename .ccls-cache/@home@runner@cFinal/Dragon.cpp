#include <iostream>
#include <fstream> 

using namespace std;

/*Create a dragon class that inherits from Character (public)*/
class Dragon: public Character {
private:
int flightPoints;

public:
/*Create a constructor that takes name and health points as input parameters and calls Character class constructor to pass these inputs.
The constructor will set isAlive to true, canFly to true and has Armor to false.
Note: When health is set to 0, the character dies.
The constructor will set flightPoints to 25.*/
Dragon(string Name, int Health):Character(Name, Health) {
    this->isAlive = true;
    this->canFly = true;
    this->hasArmor = false;
    this->flightPoints=25;
  if(Health <= 0) {
    cout<< "Dragon Dead\n";
  }
  }
/*Create a public virtual method called Attack() which takes an 2 input
c)	Input parameter 1 -  “x” – integer that indicates the strength of the attack
d)	Input parameter 2 - “obj” - object of type Character (hint: use pointer )
Call Character class Attack() method with the appropriate parameters.*/
virtual void Attack(int x, Character* obj) {
 Character::Attack(x,obj);
}
/*Create a public virtual method called TakeDamage() that takes 1 input (x as integer)
Call InvokeFlightDefense () and pass x.
Call the base class TakeDamage() method with x*/
virtual void TakeDamage(int x) {
  InvokeFlightDefense(x);
  Character::TakeDamage(x);
}
/*Create a public method called InvokeFlightDefense() that takes 1 input
b)	Input parameter 1 -  “x” – integer that indicates the strength of the attack (hint: use Pass by Reference)
Note: changing x inside the function should reflect outside too, so we receive x as reference instead of by value.
Flight Defense will reduce strength of attack as given below:
If flightPoints is greater than or equal to 20, then the character has full armor so the strength of attack (x) will be reduced by 5.
Else if flightPoints is greater than or equal to 10, then the character has partial armor so that strength of the attack(x) will be reduced by 3.
Else if flightPoints is greater than or equal to 0, then the character has partial armor so that strength of the attack(x) will be reduced by 1.
Else display “No flight defense available”
Each time this method is called, flightPoints will be reduced by 3. If flightPoints falls below 0, it should be reset to 0.*/
void InvokeFlightDefense(int &x) {
  flightPoints -= 3;
  if (flightPoints < 0) {
    flightPoints = 0;
  }
  if (flightPoints >= 20) {
    x-=5;
  } else if(flightPoints >=10) {
    x-=3;
  } else if (flightPoints >= 0) {
    x-=1;
  } else {
    cout<< "No flight defense available\n";
  }
}
/*Create a public method called Display() that takes no input
This method will do the following:
•	Call Display() method of base class Character
•	Display flightPoints.*/
void Display() {
  Character::Display();
  cout<< "Dragon has "<<flightPoints<<" flight points left.\n";
}
};