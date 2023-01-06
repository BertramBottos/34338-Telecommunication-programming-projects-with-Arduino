int a[5] = {9,2,42,5,8};
int *pointer = &a[0];
int a1 = 5; 
int b1 = 10;
int *pointer_a1 = &a1;
int *pointer_b1 = &b1;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.printf("Address of pointer is %x\n",pointer); 
  Serial.printf("Value of pointer is %d\n\n",*pointer);
  pointer++;;
  Serial.printf("Value of a is %d\n",*pointer_a1);
  Serial.printf("Value of b is %d\n\n",*pointer_b1);
  swap(pointer_a1, pointer_b1);
  delay(3000);
}

void swap(int *pointer_a, int *pointer_b){ 
  int mem = *pointer_a;
  *pointer_a = *pointer_b;
  *pointer_b = mem; 
  Serial.printf("a er nu givet ved: %d\n",*pointer_a);
  Serial.printf("b er nu givet ved: %d\n\n",*pointer_b);

}