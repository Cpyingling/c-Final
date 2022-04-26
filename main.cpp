#include <iostream>
#include <fstream> 

using namespace std;

/*Create a class called Character*/
class Character {
protected:
  string name;
  int health;
  bool isAlive;
  bool canFly;
  bool hasArmor;

public:
/*Create a constructor that takes name and health points as input parameters and sets the variables appropriately. 
The constructor will set isAlive to true, canFly to false and has Armor to false.
Note: When health is set to 0, the character dies.*/
  Character(string Name, int Health) {
    this->name=Name;
    this->health=Health;
    this->isAlive = true;
    this->canFly = false;
    this->hasArmor = false;
    if(Health <= 0) {
    cout<< "Character Dead\n";
  }
  }
/*Create a public virtual method called Display() that takes no input
This method will display name, health points and life status (Alive or Dead).*/ virtual void Display() {
   string status;
   if (isAlive == true) {
     status = "Alive";
   } else if (isAlive == false){
     status = "Dead";
   }
  cout<< "Name: " <<name<< "\nHealth: " <<health<< "\nLife status: " <<status<< "\n";
}
/*Create a public virtual method called Attack() which takes an 2 input
a)	Input parameter 1 -  “x” – integer that indicates the strength of the attack
b)	Input parameter 2 - “obj” - object of type Character (hint: use pointer )
Continue to the next step only if x is greater than or equal to 0.
Display “Attack in progress by” and the name of the Character.
Continue to the next step only if the object’s isAlive status is set to true.
Call TakeDamage() method for the object “obj” and pass x. */
virtual void Attack(int x, Character* obj) {
  if(Character::isAlive == true) {
  if(x>=0) {
    cout<< "Attack in progress by " <<name<< "\n";
    }
    if(obj->isAlive == true) {
      obj->TakeDamage(x);
    }
    } else if (Character::isAlive == false) {
      cout<< name<< " is dead and cannot attack\n";
    }
}
/*
Create a public virtual method called TakeDamage() that takes 1 input (x as integer)
This method will do the following: 
a)	if health is less than or equal to 0, exit
•	else reduce health by x points
•	check health and if health is equal to or less than 0, this method will set isAlive to false.*/
virtual void TakeDamage(int x) {
  if (health <= 0){
    cout<< name<< " has died\n";
    abort();
    }else {
    health=health - x;
    cout<< name<< " has taken " <<x<< " damage and has " <<health<< " health left\n";
    }
  if(health <= 0) {
   isAlive = false;
    cout<< name<< " has died!\n";
  }
  }
};

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

int main() {

  cout<< "Current Alive Characters:\n";
  Character c1("Charlie",100);
  Character c2("Jord",100);
  Monster m1("Monster1",150);
  Dragon d1("Dragon1",250);
  c1.Display();
  cout<<"\n";
  c2.Display();
  cout<<"\n";
  m1.Display();
  cout<<"\n";
  d1.Display();
  cout<<"\n";
  
  cout<< "Fight:\n";
  cout<<"\n";
  c1.Attack(149,&m1);
  c1.Attack(149,&m1);
  cout<<"\n";
  m1.Display();//test to ensure damage saves
  cout<<"\n";
  m1.Attack(100,&c1);
  c2.Attack(20,&m1);
  d1.Attack(50,&c2);
  c1.Attack(1,&c2);//test to attack while dead
  c2.Attack(185,&d1);
  c2.Attack(73,&d1);
  cout<<"\n";
  cout<< "After Fight:\n";
  cout<<"\n";
  c1.Display();
  c2.Display();
  m1.Display();
  d1.Display();
  
  //test to abort if taking damage and dead as instructed
  d1.TakeDamage(73);
  //test to abort if taking damage and dead as instructed
}