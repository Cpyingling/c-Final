#include <iostream>
#include <fstream> 
#include "main.cpp"
using namespace std;

/*Create a monster class that inherits from Character (public)*/
class Monster: public Character {
private: 
int armorPoints;

public:
/*Create a constructor that takes name and health points as input parameters and calls Character class constructor to pass these inputs.
The constructor will set isAlive to true, canFly to false and has Armor to true.
Note: When health is set to 0, the character dies.
The constructor will set armorPoints to 50.*/
Monster(string Name, int Health):Character(Name, Health) {
    this->isAlive = true;
    this->canFly = false;
    this->hasArmor = true;
    this->armorPoints = 50;
  if(Health <= 0) {
    cout<< "Monster Dead\n";
  }
  }
/*Create a public virtual method called Attack() which takes an 2 input
a)	Input parameter 1 -  “x” – integer that indicates the strength of the attack
b)	Input parameter 2 - “obj” - object of type Character (hint: use pointer )
Call Character class Attack() method with the appropriate parameters.*/
virtual void Attack(int x, Character* obj) {
  Character::Attack(x,obj);
}
/*Create a public virtual method called TakeDamage() that takes 1 input (x as integer)
Call InvokeArmorDefense() and pass x.
Call the base class TakeDamage() method with x*/
virtual void TakeDamage(int x) {
  InvokeArmorDefense(x);
  Character::TakeDamage(x);
  }
/*Create a public method called InvokeArmorDefense() that takes 1 input
a)	Input parameter 1 -  “x” – integer that indicates the strength of the attack (hint: use Pass by Reference)
Note: changing x inside the function should reflect outside too, so we receive x as reference instead of by value.
Defense Armor will reduce strength of attack as given below:
If armorPoints is between 25 to 50, then the character has full armor so the strength of attack (x) will be set to x/2.
If armorPoints is less than 25, then the character has partial armor so that strength of the attack(x) will be set to x/4.
armorPoints will be reduced by 5. 
If armorPoints is less than 0, reset it to 0.*/
void InvokeArmorDefense(int &x) {
  if (armorPoints >= 25 && armorPoints <= 50) {
    x/=2;
  }
  if (armorPoints < 25) {
    x/=4;
    armorPoints-=5;
  }
  if (armorPoints <0) {
    armorPoints = 0;
  }
}
/*Create a public method called Display() that takes no input
This method will do the following:
•	Call Display() method of base class Character
•	Display armorPoints.*/
void Display() {
  Character::Display();
  cout<< "Monster has "<<armorPoints<<" armor left.\n";
}
};