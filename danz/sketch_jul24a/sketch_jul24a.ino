++int BP1=13;
int BP2=8;
int b=7;
int c=6;
int d=5;
int e=4;
int x;
int y;


void setup() {
pinMode(BP2,INPUT);
pinMode(BP1,INPUT);
Serial.begin(9600);
pinMode (b,OUTPUT);
pinMode (c,OUTPUT);
pinMode (d,OUTPUT);
pinMode (e,OUTPUT);
}

void loop() {
if(digitalRead(13)==1){
nyala();
}
digitalWrite(b,0);
loop();
}


void nyala(){
if(digitalRead(BP2)==1)
 {loop();}
              
digitalWrite(b,1);
delay(555);
digitalWrite(b,0);
delay(555);
digitalWrite(c,1);
delay(555);
digitalWrite(c,0);
delay(555);
digitalWrite(d,1);
delay(555);
digitalWrite(d,0);
delay(555);
digitalWrite(e,1);
delay(555);
digitalWrite(e,0);
delay(555);
nyala();
}

