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
    cout<< name<< " has taken " <<x<< " damage and has " <<health<< " hp left\n";
    }
  if(health <= 0) {
   isAlive = false;
    cout<< name<< " has died!\n";
  }
  }
};