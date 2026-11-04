int L1=13;
int L2=12;
int L3=11;
int L4=10;

int L5=1;
int L6=2;
int L7=3;
int L8=4;

int L9=A1;
int L10=A2;
int L11=A3;
int L12=A4;



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
kedip_MATI();
kedip4();
kedip4();
kedip_MATI();
kedipall1();
kedipall2();
kedipall3();
kedipall4();
kedip_all_mati();
loop();
}



void kedip(){
digitalWrite(L1,1);
digitalWrite(L2,0);
digitalWrite(L3,1);
digitalWrite(L4,0);
delay(200);

digitalWrite(L1,0);
digitalWrite(L2,1);
digitalWrite(L3,0);
digitalWrite(L4,1);
delay(200);
}


void kedip2(){
digitalWrite(L1,1);
digitalWrite(L2,1);
digitalWrite(L3,1);
digitalWrite(L4,1);
delay(200);

digitalWrite(L1,0);
digitalWrite(L2,0);
digitalWrite(L3,0);
digitalWrite(L4,0);
delay(200);
}

void kedip3(){
digitalWrite(L1,1);
digitalWrite(L2,0);
digitalWrite(L3,0);
digitalWrite(L4,0);
delay(200);

digitalWrite(L1,0);
digitalWrite(L2,1);
digitalWrite(L3,0);
digitalWrite(L4,0);
delay(200);

digitalWrite(L1,0);
digitalWrite(L2,0);
digitalWrite(L3,1);
digitalWrite(L4,0);
delay(200);

digitalWrite(L1,0);
digitalWrite(L2,0);
digitalWrite(L3,0);
digitalWrite(L4,1);
delay(200);
}

void kedip4(){
digitalWrite(L5,1);
digitalWrite(L6,0);
digitalWrite(L7,0);
digitalWrite(L8,0);
delay(200);

digitalWrite(L5,0);
digitalWrite(L6,1);
digitalWrite(L7,0);
digitalWrite(L8,0);
delay(200);

digitalWrite(L5,0);
digitalWrite(L6,0);
digitalWrite(L7,1);
digitalWrite(L8,0);
delay(200);

digitalWrite(L5,0);
digitalWrite(L6,0);
digitalWrite(L7,0);
digitalWrite(L8,1);
delay(200);
}

void kedip_MATI(){
digitalWrite(L1,0);
digitalWrite(L2,0);
digitalWrite(L3,0);
digitalWrite(L4,0);
delay(200);

digitalWrite(L5,0);
digitalWrite(L6,0);
digitalWrite(L7,0);
digitalWrite(L8,0);
delay(200);

}

void kedipall1(){
digitalWrite(L1,1);
digitalWrite(L2,0);
digitalWrite(L3,0);
digitalWrite(L4,0);
delay(200);

digitalWrite(L5,1);
digitalWrite(L6,0);
digitalWrite(L7,0);
digitalWrite(L8,0);
delay(200);

digitalWrite(L9,1);
digitalWrite(L10,0);
digitalWrite(L11,0);
digitalWrite(L12,0);
delay(200);
}

void kedipall2(){
digitalWrite(L1,0);
digitalWrite(L2,1);
digitalWrite(L3,0);
digitalWrite(L4,0);
delay(200);

digitalWrite(L5,0);
digitalWrite(L6,1);
digitalWrite(L7,0);
digitalWrite(L8,0);
delay(200);

digitalWrite(L9,0);
digitalWrite(L10,1);
digitalWrite(L11,0);
digitalWrite(L12,0);
delay(200);
}

void kedipall3(){
digitalWrite(L1,0);
digitalWrite(L2,0);
digitalWrite(L3,1);
digitalWrite(L4,0);
delay(200);

digitalWrite(L5,0);
digitalWrite(L6,0);
digitalWrite(L7,1);
digitalWrite(L8,0);
delay(200);

digitalWrite(L9,0);
digitalWrite(L10,0);
digitalWrite(L11,1);
digitalWrite(L12,0);
delay(200);
}

void kedipall4(){
digitalWrite(L1,0);
digitalWrite(L2,0);
digitalWrite(L3,0);
digitalWrite(L4,1);
delay(200);

digitalWrite(L5,0);
digitalWrite(L6,0);
digitalWrite(L7,0);
digitalWrite(L8,1);
delay(200);

digitalWrite(L9,0);
digitalWrite(L10,0);
digitalWrite(L11,0);
digitalWrite(L12,1);
delay(200);
}

void kedip_all_mati(){
digitalWrite(L1,0);
digitalWrite(L2,0);
digitalWrite(L3,0);
digitalWrite(L4,0);
delay(200);

digitalWrite(L5,0);
digitalWrite(L6,0);
digitalWrite(L7,0);
digitalWrite(L8,0);
delay(200);

digitalWrite(L9,0);
digitalWrite(L10,0);
digitalWrite(L11,0);
digitalWrite(L12,0);
delay(200);
}










