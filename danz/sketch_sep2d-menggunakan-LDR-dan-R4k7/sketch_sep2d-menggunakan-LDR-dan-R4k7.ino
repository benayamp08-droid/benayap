//bisa cuyyy

int x;
int l1=2;
int l2=3;
int l3=4;
int l4=5;
int l5=6;

int a=7;
int b=8;
int c=9;
int d=A2;
int e=11;
int f=12;
int g=13;


void setup() {
  // put your setup code here, to run once:
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(l3,OUTPUT);
pinMode(l4,OUTPUT);
pinMode(l5,OUTPUT);

pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);


Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x=analogRead(A5);
Serial.println(x);
delay(100);

if(x>400){
lima();
}

if(x>500){
empat();
}

if(x>600){
tiga();
}

if(x>700){
dua();
}

if(x>800){
satu();
}

if(x>900){
nol();
}





}
void nol(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);
  digitalWrite(l1,0);
}

void satu(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  digitalWrite(l2,0);
}
void dua(){
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);
  digitalWrite(l3,0);
}

void tiga(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);
  digitalWrite(l4,0);
}
void empat(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,1);
  digitalWrite(l4,0);
}

void lima(){
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  digitalWrite(l5,0);
}






