int l1=13; 
int bp=12; 
int x; 

void setup() { 
  pinMode(bp,INPUT); 
  pinMode(l1,OUTPUT); 
} 

void loop(){ 
  
  digitalWrite(l1,0); 
  x=digitalRead(bp); 
  if(x==1){ 
    delay(200);
    nyala(); 
  } 
}

void nyala() { 

  digitalWrite(l1,1); 
  x=digitalRead(bp); 
  if(x==1) {
    delay(200);
    loop();
    
  }
  nyala(); 
}