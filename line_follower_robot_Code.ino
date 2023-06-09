 /* Raheek Ayman Helal 
    Dr.Manal El-Belkasy
    Computer Science
    level(1)
 */ 

 // defining the ouput pins of the arduino
 #define Motor11 7
 #define Motor21 9
 #define PWMmotor1 5
 #define PWMmotor2 10


 int valuePWM1=100;      // speed motor 1 
 int valuePWM2=100;      // speed motor 2 
 
void setup() 
{
  Serial.begin(9600);

//defining the output & the input pins
  pinMode(Motor11,OUTPUT);
  pinMode(Motor21,OUTPUT);
  pinMode(PWMmotor1,OUTPUT);
  pinMode(PWMmotor2,OUTPUT);
  
  pinMode(A0, INPUT);       // initialize Right sensor as an inut
  pinMode(A1, INPUT);       // initialize Left sensor as an input

 }

void loop()
{

  int LEFT_SENSOR = analogRead(A0);
  int RIGHT_SENSOR = analogRead(A1);
  
if( RIGHT_SENSOR>200 && LEFT_SENSOR>200)                //FORWARD
 {
            digitalWrite(Motor11, HIGH);
            digitalWrite(Motor21, HIGH);
            analogWrite(PWMmotor1, valuePWM1);
            analogWrite(PWMmotor2, valuePWM1);
 }

 else if(RIGHT_SENSOR<36 || LEFT_SENSOR>200)            //LEFT
 {
            digitalWrite(Motor11, LOW);
            digitalWrite(Motor21, HIGH);
            analogWrite(PWMmotor1, valuePWM2);
            analogWrite(PWMmotor2, valuePWM2);
 }

else if(RIGHT_SENSOR>200 || LEFT_SENSOR<36)             //RIGHT
 {
              digitalWrite(Motor11, HIGH);
              digitalWrite(Motor21, LOW);
              analogWrite(PWMmotor1, valuePWM2);
              analogWrite(PWMmotor2, valuePWM2);
 }

else                                                    //STOP
 {
              digitalWrite(Motor11, LOW);
              digitalWrite(Motor21, LOW);
 }
}