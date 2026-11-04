
int buton=12;
int mboten=13;
int x;
int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=9;


int i=A1;
int j=A2;
int k=A3;
int l=A4;
int m=A5;
int n=10;
int o=11;

                                        

void setup() {
  // put your setup code here, to run once:


pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
pinMode(i,OUTPUT);
pinMode(j,OUTPUT);
pinMode(k,OUTPUT);
pinMode(l,OUTPUT);
pinMode(m,OUTPUT);
pinMode(n,OUTPUT);
pinMode(o,OUTPUT);

pinMode(mboten, INPUT_PULLUP);
pinMode(buton, INPUT_PULLUP);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(mboten)== 0){
  x = x + 1;
  Serial.println(x);
  delay(200);
 }

if(digitalRead(buton)== 0){
  x = x -1;
  Serial.println(x);
  delay(200);

if(digitalRead(buton)== 0){
  x = 0;
 }


if(x == 21){
  x = 20;
}
if(x == -1){
  x = 0;

}
if(x == 0){
  nol();
}
if(x == 1){
  satu();
}
if(x == 2){
  dua();
}
if(x == 3){
  tiga();
}
if(x == 4){
  empat();
}
if(x == 5){
  lima();
}
if(x == 6){
  enam();
}
if(x == 7){
  tujuh();
}
if(x == 8){
  delapan();
}
if(x == 9){
  sembilan();
}
if(x == 10){
  sepuluh();
}
if(x == 11){
  sebelas();
}
if(x == 12){
  duabelas();
}
if(x == 13){
  tigabelas();
}
if(x == 14){
  empatbelas();
}
if(x == 15){
  limabelas();
}
if(x == 16){
  enambelas();
}
if(x == 17){
  tujuhbelas();
}
if(x == 18){
  delapanbelas();
}
if(x == 19){
  sembilanbelas();
}
if(x == 20){
  duapuluh();
}
}


void nol(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,0);
  digitalWrite(n,0);
  digitalWrite(o,1);
}

void satu(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,0);
  digitalWrite(n,0);
  digitalWrite(o,1);
}
void dua(){
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,0);
  digitalWrite(n,0);
  digitalWrite(o,1);
}

void tiga(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,0);
  digitalWrite(n,0);
  digitalWrite(o,1);

}
void empat(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,0);
  digitalWrite(n,0);
  digitalWrite(o,1);
}

void lima(){
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,0);
  digitalWrite(n,0);
  digitalWrite(o,1);
}

void enam(){
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,0);
  digitalWrite(n,0);
  digitalWrite(o,1);
}

void tujuh(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,1);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,0);
  digitalWrite(n,0);
  digitalWrite(o,1);

}

void delapan(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,0);
  digitalWrite(n,0);
  digitalWrite(o,1);
}
void sembilan(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,0);
  digitalWrite(n,0);
  digitalWrite(o,1);
}
void sepuluh(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,1);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,1);
  digitalWrite(l,1);
  digitalWrite(m,1);
  digitalWrite(n,1);
  digitalWrite(o,1);
  
}
void sebelas(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,1);
  digitalWrite(l,1);
  digitalWrite(m,1);
  digitalWrite(n,1);
  digitalWrite(o,1);
  
}
void duabelas(){
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,1);
  digitalWrite(l,1);
  digitalWrite(m,1);
  digitalWrite(n,1);
  digitalWrite(o,1);
  
}
void tigabelas(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,1);
  digitalWrite(l,1);
  digitalWrite(m,1);
  digitalWrite(n,1);
  digitalWrite(o,1);
  
}
void empatbelas(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,1);
  digitalWrite(l,1);
  digitalWrite(m,1);
  digitalWrite(n,1);
  digitalWrite(o,1);
  
}
void limabelas(){
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,1);
  digitalWrite(l,1);
  digitalWrite(m,1);
  digitalWrite(n,1);
  digitalWrite(o,1);
  
}
void enambelas(){
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,1);
  digitalWrite(l,1);
  digitalWrite(m,1);
  digitalWrite(n,1);
  digitalWrite(o,1);
  
}
void tujuhbelas(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,1);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,1);
  digitalWrite(l,1);
  digitalWrite(m,1);
  digitalWrite(n,1);
  digitalWrite(o,1);
  
}
void delapanbelas(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);

  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,1);
  digitalWrite(l,1);
  digitalWrite(m,1);
  digitalWrite(n,1);
  digitalWrite(o,1);
  
}
void sembilanbelas(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);


  digitalWrite(i,0);
  digitalWrite(j,0);
  digitalWrite(k,1);
  digitalWrite(l,1);
  digitalWrite(m,1);
  digitalWrite(n,1);
  digitalWrite(o,1);
  
}
void duapuluh(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,1);

  digitalWrite(i,0);
  digitalWrite(j,1);
  digitalWrite(k,0);
  digitalWrite(l,0);
  digitalWrite(m,1);
  digitalWrite(n,0);
  digitalWrite(o,0);
}








