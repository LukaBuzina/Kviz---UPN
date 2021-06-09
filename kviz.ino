int st = 1;int R1 = A5;int R2 = A4;int R3 = 13;
int B45 = 3;int B2 = 4;int B3 = 5;int W1 = 6;
int W2 = 7;int W3 = 8;int TR = 10;int TB = 9;
int TW = 11;int RESET = 12;int r;int w;int b;
int sez[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int sez2[] = {R1, R2, R3, B45, B2, B3, W1, W2, W3};
boolean bo1 = false;
int gumb;
void setup(){
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(B45, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(B3, OUTPUT);
  pinMode(W1, OUTPUT);
  pinMode(W2, OUTPUT);
  pinMode(W3, OUTPUT);
  pinMode(TR, INPUT_PULLUP);
  pinMode(TB, INPUT_PULLUP);
  pinMode(TW, INPUT_PULLUP);
  pinMode(RESET, INPUT_PULLUP);
  Serial.begin(9600);
 
}

void loop(){
  preveri(TR, 0);
  preveri(TB, 3);
  preveri(TW, 6);

  delay(100);
  if (st >= 4){
    for (int i = 0; i < 9; i++){
      digitalWrite(sez2[i], sez[i]);
      Serial.println(sez2[i]);
    }
  }
  if (digitalRead(RESET) == 0){
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(B45, LOW);
    digitalWrite(B2, LOW);
    digitalWrite(B3, LOW);
    digitalWrite(W1, LOW);
    digitalWrite(W2, LOW);
    digitalWrite(W3, LOW);
    for (int i = 0; i < 9; i++){
      sez[i] = 0;
    }
    st=1;
    gumb = 0;
  }
  Serial.print(st);
 
}
void preveri(int X, int c){
  if (digitalRead(X) == 0){
    pristej(X);
    if (st == 2) {
      sez[c] = 1;
      sez[c + 1] = 1;
      sez[c + 2] = 1;
      delay(20);
      Serial.println("Prvi" + String(st));
      Serial.println(sez2[c]);
      Serial.println(sez2[c + 1]);
      Serial.println(sez2[c + 1]);
     
    }
    else if (st == 3) {
      sez[c] = 1;
      sez[c + 1] = 1;
      delay(20);
      Serial.println("Drugi" + String(st));
      Serial.println(sez2[c]);
      Serial.println(sez2[c + 1]);
    }
    else if (st == 4) {
      sez[c] = 1;
      delay(20);
      Serial.println("Tretji" + String(st));
      Serial.println(sez2[c]);
    }
   
  }  
}
void pristej(int X) {
  if (gumb != X) {
    st++;
    gumb = X;
  }
}
