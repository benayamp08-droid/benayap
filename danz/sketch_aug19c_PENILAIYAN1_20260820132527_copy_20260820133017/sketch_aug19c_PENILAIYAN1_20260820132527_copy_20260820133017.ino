int TB1 = 13;
int TB2 = 12;


int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int y;
int x; 
int l1=10;

void setup() {
  pinMode(TB1,INPUT_PULLUP);    
  pinMode(TB2,INPUT_PULLUP); 
  
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(l1,OUTPUT);

  Serial.begin(9600);

}

void loop(){
  digitalWrite(l1,1);
  digitalWrite(A,1);
  digitalWrite(B,1);
  digitalWrite(C,1);
  digitalWrite(D,1);
  digitalWrite(E,1);
  digitalWrite(F,1);
  digitalWrite(l1,1);

x=digitalRead(TB1);
y=digitalRead(TB2);
if(x==0){
delay(200);
digitalWrite(l1,0);
delay(3000);
digitalWrite(l1,1);
nyala();
}
loop();
}


void nyala(){
  a();
  delay(200);
  matikan();
  b();
  delay(200);
  matikan();
  c();
  delay(200);
  matikan();
  d();
  delay(200);
  matikan();
  e();
  delay(200);
  matikan();
  f();
  delay(200);
  matikan();
  nyala();
}


void a() {
  digitalWrite(A, 0); 
  digitalWrite(B, 1); 
  digitalWrite(C, 1);
  digitalWrite(D, 1); 
  digitalWrite(E, 1); 
  digitalWrite(F, 1);
  }
void b() {
  digitalWrite(A, 1);
  digitalWrite(B, 0); 
  digitalWrite(C, 1);
  digitalWrite(D, 1); 
  digitalWrite(E, 1); 
  digitalWrite(F, 1);
}
void c() {
  digitalWrite(A, 1); 
  digitalWrite(B, 1); 
  digitalWrite(C, 0);
  digitalWrite(D, 1); 
  digitalWrite(E, 1); 
  digitalWrite(F, 1);
}
void d() {
  digitalWrite(A, 1); 
  digitalWrite(B, 1); 
  digitalWrite(C, 1);
  digitalWrite(D, 0); 
  digitalWrite(E, 1); 
  digitalWrite(F, 1);
}
void e() {
  digitalWrite(A, 1); 
  digitalWrite(B, 1); 
  digitalWrite(C, 1);
  digitalWrite(D, 1); 
  digitalWrite(E, 0); 
  digitalWrite(F, 1);
}
void f() {
  digitalWrite(A, 1); 
  digitalWrite(B, 1); 
  digitalWrite(C, 1);
  digitalWrite(D, 1); 
  digitalWrite(E, 1);
  digitalWrite(F, 0);
}

void matikan() {
  y=digitalRead(TB2);
  if(y==0){
  delay(200);
  digitalWrite(A, 1); 
  digitalWrite(B, 1); 
  digitalWrite(C, 1);
  digitalWrite(D, 1); 
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  loop();
}
}


