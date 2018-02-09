
int Asia_Oceania_Red = 0;    // how bright the red LED is
int Africa_ME_Yellow = 0;    // how bright the yellow LED is
int Visited_White = 0;    // how bright the yellow LED is
int Americas_Blue = 0;    // how bright the yellow LED is
int Europe_Green = 0;


int fadeAmount = 1;    // how many points to fade the LED by
int state = 0;

void setup()  {
  // declare pins to be outputs:
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
} 

void loop()  {
  if(state==0){ //North and South American places in blue
    analogWrite(6, Americas_Blue);
    Americas_Blue = Americas_Blue + fadeAmount;
    if (Americas_Blue == 0 || Americas_Blue == 255) {
    fadeAmount = -fadeAmount; 
  }
    if (Americas_Blue == 0){
      state = state+1;
      analogWrite(6, LOW);
    }
  }


  else if(state==1){ //European places in green
    analogWrite(10, Europe_Green);
    Europe_Green = Europe_Green + fadeAmount;
    if (Europe_Green == 0 || Europe_Green == 255) {
    fadeAmount = -fadeAmount; 
  }
    if (Europe_Green == 0){
      state = state+1;
      analogWrite(10, LOW);
    }
  }


  else if(state==2){ //African and Middle Eastern places in yellow
    analogWrite(3, Africa_ME_Yellow);
    Africa_ME_Yellow = Africa_ME_Yellow + fadeAmount;
    if (Africa_ME_Yellow == 0 || Africa_ME_Yellow == 255) {
    fadeAmount = -fadeAmount; 
  }
    if (Africa_ME_Yellow == 0){
      state = state+1;
      analogWrite(3, LOW);
    }
  }
  
  if(state==3){  //Asia, SE Asia, Oceania in red
    analogWrite(9, Asia_Oceania_Red);
    Asia_Oceania_Red = Asia_Oceania_Red + fadeAmount;
    if (Asia_Oceania_Red == 0 || Asia_Oceania_Red == 255) {
    fadeAmount = -fadeAmount ; 
  } 
    if (Asia_Oceania_Red == 0){
      state = state+1;
      analogWrite(9, LOW);
    }
  }
  

  else if(state==4){ //Places already visited are in white
    analogWrite(5, Visited_White);
    Visited_White = Visited_White + fadeAmount;
    if (Visited_White == 0 || Visited_White == 255) {
    fadeAmount = -fadeAmount; 
  }
    if (Visited_White == 0){
      state = 0;
      analogWrite(5, LOW);
    }
  }

  // wait for 3 milliseconds to see the dimming effect    
  delay(6);
}

