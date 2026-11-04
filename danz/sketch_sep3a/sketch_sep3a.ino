int y;
int x;
int potensi=A5;


void setup() {
  // put your setup code here, to run once:
 pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
x=analogRead(A5);
Serial.println(y);
y=map(x,0,1023,0,255);
delay(100);

analogWrite(3,y);
analogWrite(5,y);
}
















































