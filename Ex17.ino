
struct Animal {
  int weight, amount, age, ID;
  char gender;
  bool houseAnimal;
};
struct Animal monkey;
struct Animal lion;

void setup() {
  Serial.begin(115200);

  monkey.gender = 'M';
  monkey.ID = 8;
  monkey.houseAnimal = false;
  monkey.weight = 50; 
  monkey.amount = 100; 
  monkey.age = 9;

  lion.gender = 'F';
  lion.ID =152;
  lion.houseAnimal = false;
  lion.weight = 150; 
  lion.amount = 300; 
  lion.age = 6;
  delay(3000);
}

void loop() {

  Serial.println("Start");
  
  printAnimal(lion, "Lion");
  delay(3000);
  printAnimal(monkey, "Monkey");
  delay(3000);

  swapWeight(&lion,&monkey);

 
  ComparaAnimal(&lion,&monkey);
  Serial.println("End");
  delay(70000);
}

void printAnimal(struct Animal a, String name) {
  Serial.print("    ");Serial.println(name);
  Serial.print("Weight: ");
  Serial.println(a.weight);
  Serial.print("Amount: ");
  Serial.println(a.amount);
  Serial.print("Age: ");
  Serial.println(a.age);
  Serial.print("Gender: ");
  Serial.println(a.gender);
  Serial.print("is it cable of living in a house: ");
  Serial.println(a.houseAnimal);
  Serial.print("ID: ");
  Serial.println(a.ID);
}

void swapWeight (struct Animal *a, struct Animal *b) {
  int mem = b->weight;
  b->weight = a->weight;
  a->weight = mem;
}

void ComparaAnimal(struct Animal *a, struct Animal *b) {
  int age_a = a->age, age_b = b->age, id_a = a->ID, id_b = b->ID;

  if(age_a < age_b && id_b < id_a || age_a > age_b && id_b > id_a) {
    int tempID = a->ID;
    a->ID = b->ID;
    b->ID = tempID;
  }

}