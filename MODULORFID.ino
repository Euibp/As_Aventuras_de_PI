#include <LiquidCrystal.h>


int RFIDResetPin = 32;

//Register your RFID tags here
char tag1[13] = "1A007C58DFE1";
char tag2[13] = "1A007C58447A";
char tag3[13] = "1A007C5B4A77";
char tag4[13] = "1A007C593B04";
char tag5[13] = "1A007C581E20";
char tag6[13] = "1A007C5B4D70";
char tag7[13] = "1A007C594F70";
char tag8[13] = "1A007C58201E";

LiquidCrystal lcd(12,14,2,0,4,5);

void setup(){
  Serial.begin(9600);
  
  pinMode(RFIDResetPin, OUTPUT);
  digitalWrite(RFIDResetPin, HIGH);

  lcd.begin(16, 2);
  lcd.print("Aventuras PI");

  //pinMode(5, OUTPUT);
  //pinMode(4, OUTPUT);
  //pinMode(0, OUTPUT);
  //pinMode(2, OUTPUT);
  //pinMode(14, OUTPUT);
  //pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
}

void loop(){
  
  char tagString[13];
  int index = 0;
  boolean reading = false;

  while(Serial.available()){
  
    int readByte = Serial.read(); //read next available byte
    
    if(readByte == 2) reading = true; //begining of tag
    if(readByte == 3){ 
      reading = false; 
      tagString[index] = '\0'; //end of tag
      //Serial.println("  /");    
      //Serial.println(tagString);
    }
    
    if(reading && readByte != 2 && readByte != 10 && readByte != 13){
    //store the tag
    tagString[index] = (char)readByte;
    //Serial.print((char)readByte);

    
    index ++;
    }
  }

checkTag(tagString); //Check if it is a match
//clearTag(tagString); //Clear the char of all value
  for(int i = 0; i < strlen(tagString); i++){
   tagString[i] = 0;
  }

resetReader(); //eset the RFID reader
}

void checkTag(char tag[]){
  ///////////////////////////////////
  //Check the read tag against known tags
  ///////////////////////////////////
  
  if(strlen(tag) == 0) return; //empty, no need to contunue
  lcd.begin(16, 2);
  lcd.print( String("ID:")+tag+String(" "));
  lcd.setCursor(0, 1);
  lcd.print(String("R$:")/*+valor*/);
 
//  if(compareTag(tag, tag1)){ // if matched tag1, do this
//    lightLED(5);
//  }else if(compareTag(tag, tag2)){ //if matched tag2, do this
//    lightLED(4);  
//  }else if(compareTag(tag, tag3)){ //if matched tag2, do this
//    lightLED(0);
//  }else if(compareTag(tag, tag4)){ //if matched tag2, do this
//    lightLED(2);
//  }else if(compareTag(tag, tag5)){ //if matched tag2, do this
//    lightLED(14);
//  }else if(compareTag(tag, tag6)){ //if matched tag2, do this
//    lightLED(12);
//  }else if(compareTag(tag, tag7)){ //if matched tag2, do this
//      lightLED(13);
//    }else if(compareTag(tag, tag8)){ //if matched tag2, do this
//     lightLED(15);}else{
  Serial.println(tag); //read out any unknown tag
  //}
}

void lightLED(int pin){
///////////////////////////////////
//Turn on LED on pin “pin” for 250ms
///////////////////////////////////
Serial.println(pin);

  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
}

void resetReader(){
  ///////////////////////////////////
  //Reset the RFID reader to read again.
  ///////////////////////////////////
  digitalWrite(RFIDResetPin, LOW);
  digitalWrite(RFIDResetPin, HIGH);
  delay(150);
}

void clearTag(char one[]){
///////////////////////////////////
//clear the char array by filling with null – ASCII 0
//Will think same tag has been read otherwise
///////////////////////////////////
  for(int i = 0; i < strlen(one); i++){ 
    one[i] = 0; 
  } 
} 

boolean compareTag(char one[], char two[]){ 
  /////////////////////////////////// 
  //compare two value to see if same, 
  //strcmp not working 100% so we do this 
  /////////////////////////////////// 
  if(strlen(one) == 0) return false; //empty 
  for(int i = 0; i < 12; i++){ 
    if(one[i] != two[i]) return false; 
  } 
  return true; //no mismatches 
}
