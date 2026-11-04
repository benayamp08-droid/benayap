int L1=13;
int L2=12;
int L3=11;
int L4=10;

int L5=1;
int L6=2;
int L7=3;
int L8=4;





void setup() {
  // put your setup code here, to run once:
pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);
pinMode(L4,OUTPUT);
pinMode(L5,OUTPUT);
pinMode(L6,OUTPUT);
pinMode(L7,OUTPUT);
pinMode(L8,OUTPUT);
}

void loop() {
kedip();
kedip();
kedip2();
kedip2();
kedip3();
kedip3();
kedip();
kedip();
}



void kedip(){
digitalWrite(L1,1);
digitalWrite(L2,0);
digitalWrite(L3,1);
digitalWrite(L4,0);
delay(500);

digitalWrite(L1,0);
digitalWrite(L2,1);
digitalWrite(L3,0);
digitalWrite(L4,1);
delay(500);
}


void kedip2(){
digitalWrite(L1,1);
digitalWrite(L2,1);
digitalWrite(L3,1);
digitalWrite(L4,1);
delay(500);

digitalWrite(L1,0);
digitalWrite(L2,0);
digitalWrite(L3,0);
digitalWrite(L4,0);
delay(500);
}

void kedip3(){
digitalWrite(L1,1);
digitalWrite(L2,0);
digitalWrite(L3,0);
digitalWrite(L4,0);
delay(500);

digitalWrite(L1,0);
digitalWrite(L2,1);
digitalWrite(L3,0);
digitalWrite(L4,0);
delay(500);

digitalWrite(L1,0);
digitalWrite(L2,0);
digitalWrite(L3,1);
digitalWrite(L4,0);
delay(500);

digitalWrite(L1,0);
digitalWrite(L2,0);
digitalWrite(L3,0);
digitalWrite(L4,1);
delay(500);
}

void kedip4(){
digitalWrite(L5,1);
digitalWrite(L6,0);
digitalWrite(L7,0);
digitalWrite(L8,0);
delay(500);

digitalWrite(L5,0);
digitalWrite(L6,1);
digitalWrite(L7,0);
digitalWrite(L8,0);
delay(500);

digitalWrite(L5,0);
digitalWrite(L6,0);
digitalWrite(L7,1);
digitalWrite(L8,0);
delay(500);

digitalWrite(L5,0);
digitalWrite(L6,0);
digitalWrite(L7,0);
digitalWrite(L8,1);
delay(500);
}



















