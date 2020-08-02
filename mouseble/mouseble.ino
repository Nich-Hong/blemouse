#include <Mouse.h>
int num = 0;

int leftclick = 2, rightclick = 3, up = 8, down = 9, left = 11, right = 12, dpi=13;
int dpimultiply = 4;

int leftmousestate = 0, rightmousestate = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(leftclick,INPUT);
  pinMode(rightclick, INPUT);
  pinMode(up,INPUT);
  pinMode(down, INPUT);
  pinMode(left,INPUT);
  pinMode(right, INPUT);
  pinMode(dpi, INPUT);
  Serial.begin(9600);
  Mouse.begin();
}

void loop() {
   int u=-1, r=1,l=-1, d=1;
   dpiedit(u,d,r,l, dpimultiply);
  // put your main code here, to run repeatedly:
    if(digitalRead(leftclick) == HIGH){
      leftmousestate=HIGH;
    }
    else if(leftmousestate == HIGH && digitalRead(leftclick) == LOW){
      
      Mouse.click(MOUSE_LEFT);
      leftmousestate=LOW;
    }
    else if(digitalRead(rightclick) == HIGH){
        rightmousestate=HIGH;
    }
    else if(rightmousestate == HIGH && digitalRead(rightclick) == LOW){     
      Mouse.click(MOUSE_RIGHT);
      rightmousestate=LOW;
    }
    else if(digitalRead(up) == HIGH){
       if(digitalRead(left)==HIGH)
          Mouse.move(l,u,0);
        else if(digitalRead(right)==HIGH)
          Mouse.move(r,u,0);
        else
          Mouse.move(0,u,0);
    }
    else if(digitalRead(down) == HIGH){
        if(digitalRead(left)==HIGH)
          Mouse.move(l,d,0);
        else if(digitalRead(right)==HIGH)
          Mouse.move(r,d,0);
        else
          Mouse.move(0,d,0);
    }
    else if(digitalRead(left)==HIGH){
        Mouse.move(l,0,0);
    }
    else if(digitalRead(right)==HIGH){
        Mouse.move(r,0,0);
    }
    else if(digitalRead(dpi) == HIGH){
      if(num ==0){
        dpimultiply+=2;
        if(dpimultiply==10){
          dpimultiply = 1;
        }
      }
       Serial.println(dpimultiply);
      num++;
    }
  else {
    num=0;
  }
  delay(10);
}
void dpiedit(int&u, int&d, int&r, int&l, int&dpis){
  u=u*dpis;
  d=d*dpis;
  r=r*dpis;
  l=l*dpis;
}
