int TB1 = 13;
int TB2 = 12;


int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 9;
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

  b();
  delay(200);

  c();
  delay(200);

  d();
  delay(200);

  e();
  delay(200);

  f();
  delay(200);

  nyala();
}


void a(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);

}

void b(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);


}
void c(){
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);

}

void d(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);


}
void e(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);

}

void f(){
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
}


}
}