
//zoomkat 11-12-13 String capture and parsing 
//from serial port input (via serial monitor)
//and print result out serial port
//copy test strings and use ctrl/v to paste in
//serial monitor if desired
// * is used as the data string delimiter
// , is used to delimit individual data

String readString;
String x_pos;
String y_pos;
String z_pos;

int ind1;
int ind2;
int ind3;
 
void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  if (Serial.available())  {
    char c = Serial.read();  //gets one byte from serial buffer
    if (c == '\n') {     
      ind1 = readString.indexOf(',');  //finds location of first ,
      x_pos = readString.substring(0, ind1);   //captures first data String
      ind2 = readString.indexOf(',', ind1 + 1);   //finds location of second ,
      y_pos = readString.substring(ind1 + 1, ind2);   //captures second data String
      z_pos = readString.substring(ind2 + 1);

      Serial.print("x_pos = ");
      Serial.print(x_pos);
      Serial.print("y_pos = ");
      Serial.print(y_pos);
      Serial.print("z_pos = ");
      Serial.print(z_pos);
      Serial.println("HellO");
     
      readString=""; //clears variable for new input
      x_pos="";
      y_pos="";
      z_pos="";
    } 
    else {     
      readString += c; //makes the string readString
    }
  }
}
