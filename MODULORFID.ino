#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
 
//const char* ssid = "ASUS_Z00VD";
//const char* password = "9bd15jk4";
const char* ssid = "";
const char* password = "";

const char* Ipv4 = "192.168.25.52";
String Road = "/Aventuras_PI/PHP_Insert.php";
String OfNoReturn = "/Aventuras_PI/PHP_Remove.php";
  

IPAddress bd_IpAddr(127,0,0,1);
char* bd_user = "NodMCU";
char* bd_password = "richardParker18";

WiFiServer server(80);
 
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

  //##########################################
  // Conectando ao Wifi
   Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  
  //##########################################
 
  // Conectando ao Banco de Dados
  //##########################################
//    WiFiClient client;
//    MySQL_Connection conn((Client *)&client);
//    
//    Serial.println("Connecting to database");
//    Serial.println(bd_IpAddr);
//
//    while (conn.connect(bd_IpAddr, 3306, bd_user, bd_password) != true) {
//      delay(100);
//      Serial.print ( "." );
//    }
//  
//    Serial.println("");
//    Serial.println("Connected to SQL Server!");  

  //##########################################  
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
  char regString[13];
  int index = 0;
  boolean reading = false;
  
  clearTag(tagString);
  //for(int i = 0; i < strlen(tagString); i++){
   //tagString[i] = 0;
  //}
  
  while(Serial.available()){
  
    int readByte = Serial.read(); //read next available byte
    
    if(readByte == 2) reading = true; //begining of tag
    if(readByte == 3){ 
      reading = false; 
      tagString[index] = '\0'; //end of tag
      strcpy(regString,tagString);
    }
    
    if(reading && readByte != 2 && readByte != 10 && readByte != 13){   //store the tag
    tagString[index] = (char)readByte;
    index ++;
    }
  }

checkTag(tagString); //Check if it is a match
resetReader(); //Reset the RFID reader

//##########################################
//  WiFiClient client = server.available();
//  if (!client) {
//    return;
//  }
// 
//  // Wait until the client sends some data
//  Serial.println("new client");
//  while(!client.available() && index<1500){
//    delay(1);
//    index++;
//  }
// 
//  // Read the first line of the request
//  String request = client.readStringUntil('\r');
//  Serial.println(request);
//  client.flush();
//  Serial.println("Request");
//   
//  // Match the request
// 
//  int value = LOW;
//  if (request.indexOf("/LED=ON") != -1)  {
//    digitalWrite(13, HIGH);
//    value = HIGH;
//  }
//  if (request.indexOf("/LED=OFF") != -1)  {
//    digitalWrite(13, LOW);
//    value = LOW;
//  }
//
//  Serial.println("LEDING"); 
//// Set ledPin according to the request
////digitalWrite(ledPin, value);
// 
//  // Return the response
//  client.println("HTTP/1.1 200 OK");
//  client.println("Content-Type: text/html");
//  client.println(""); //  do not forget this one
//  client.println("<!DOCTYPE HTML>");
//  client.println("<html>");
// 
//  client.print("Led is now: ");
// 
//  if(value == HIGH) {
//    client.print("On");
//  } else {
//    client.print("Off");
//  }
//  client.println("<br>");
//  client.println(regString);
//  client.println("<br><br>");
//  //client.println(String("<br>")+tagString+String("<br>"));
//  client.println("<a href=\"/LED=ON\"\"><button>On </button></a>");
//  client.println("<a href=\"/LED=OFF\"\"><button>Off </button></a><br />");  
//  client.println("</html>");
//
//  delay(1);
//  Serial.println("Client disonnected");
//  Serial.println("");
  //##########################################
}

void checkTag(char tag[]){
  ///////////////////////////////////
  //Check the read tag against known tags
  ///////////////////////////////////
  WiFiClient PHPserver;
  
  if(strlen(tag) == 0) return; //empty, no need to contunue
  lcd.begin(16, 2);
  lcd.print( String("ID:")+tag+String(" "));
  lcd.setCursor(0, 1);
  lcd.print(String("COR: ")/*+valor*/);

  //Acesso ao Banco de Dados
  //##################################################
  String line = ""; 
  int cont = 0; 
  if(!PHPserver.connect(Ipv4,80)){
        Serial.println("Falha de Conexao");
        return;
      }
    Serial.println("Connect");
    //client.print(String("GET ")+ Road + " HTTP/1.1\r\n" + "Host: " + Ipv4 + "\r\n" + "Connection: close\r\n\r\n");
    //Serial.println("GET /Aventuras_PI/PHP_Collect.php?tag=\"" + String(tag) +"\"&local=Richard_Parcker");
    PHPserver.println("GET /Aventuras_PI/PHP_Collect.php?tag=\"" + String(tag) +"\"&local=Richard_Parcker" + " HTTP/1.1");
    PHPserver.println(String("Host: ") + Ipv4);
    PHPserver.println("Connection: close");
    PHPserver.println();
    
    unsigned long timeout = millis();
    while (PHPserver.available() == 0){
      if(millis()-timeout >5000){
        Serial.println("Client Timeout");
        PHPserver.stop();
        return;
       }
      }
      
    PHPserver.readStringUntil('*');
    while (PHPserver.available()){
      line = PHPserver.readStringUntil('*');
      switch (cont){
        case 0: // Inserindo(I) ou Removendo (R)
           if(line != "INVALIDO"){  
             lcd.setCursor(15, 1);
             lcd.print(line);
             Serial.println(line);
           }else{      
             lcd.setCursor(0, 1);
             lcd.print(line + "        ");
            } ;
          break;
        case 1: //Cor da Caixa
         lcd.setCursor(5, 1);
         lcd.print(line);
         Serial.println(line);
        break; // Preço da Caixa Se quiser mostrar
        case 2:
        break;
//          case 3: // Tag para monstrar que está no banco de dados
//          break;
//          case 4:// Recipiente onde estava a tag
//          break
        default:
        break; 
        }
        cont++;       
      }
    Serial.println("End");
    
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
