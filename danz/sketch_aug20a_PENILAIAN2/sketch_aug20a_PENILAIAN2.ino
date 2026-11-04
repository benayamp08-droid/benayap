int TB1 = 13;
int TB2 = 12;


int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 9;
int y;
int x; 
int l1=10;
int l2=A5;


void setup() {
  pinMode(TB1,INPUT_PULLUP);    
  pinMode(TB2,INPUT); 
  
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(l2,OUTPUT);

  Serial.begin(9600);

}

void loop(){

  if (digitalRead(TB1) == 0) {
    digitalWrite(l1, 1);
  }
    if (digitalRead(l1) == 1);
    if (digitalRead(TB2) == 1);
     
    
    }
    
void nyala(){
  A();
  delay(200);
  B();
  delay(200);
  C();
  delay(200);
  D();
  delay(200);
  E();
  delay(200);
  F();
  delay(200);
}

void A(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);

}

void B(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);


}
void C(){
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);

}

void D(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);


}
void E(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);

}

void F(){
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
}




}







