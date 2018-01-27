int tempPin = A1;    // the output pin of LM35

int fan = 11;        // the pin where fan is

int led = 8;         // led pin
int temp;

int tempMin = 35;    // the temperature to start the fan

int tempMax = 100;   // the maximum temperature when fan is at 100%

int fanSpeed;
 


void setup() 

{
  
	Serial.begin(9600);        // open the serial port at 9600 bps:
  
	pinMode(fan, OUTPUT);      //Defining Pin 11 as Output
  
	pinMode(led, OUTPUT);      //Defining Pin 8 as Output
  
	pinMode(tempPin, INPUT);   //Defining Pin A1 as Input

}



void loop() 

{
	temp = readTemp();        // get the temperature
 
  
	if(temp < tempMin)        // if temp is lower than minimum temp
	{   
    
		digitalWrite(fan, LOW);    //Turn off fan
 
	} 
  
	
	if((temp >= tempMin) && (temp <= tempMax))   // if temperature is higher than minimum and lower than the maximum temperature
 
	{  
       
		fanSpeed = map(temp, tempMin, tempMax, 32, 255);   // Setting the actual speed of fan
 
		analogWrite(fan, fanSpeed);                        // spin the fan at the "fanSpeed" speed
 
	}
	
	if(temp > tempMax)          // if temp is higher than tempMax
   
	{
		digitalWrite(led, HIGH);  // turn on led 
   
	} 
   
	else 
   
	{
		digitalWrite(led, LOW);   // else turn of led 
   
	}  
   
  
	
	Serial.print("Temperature is: ");      // prints a sentence
  
	Serial.print("\t");                    // prints a tab
  
	Serial.print(temp);                    // print the temperature value
  
	Serial.print("*C");                    // prints the unit
  
	Serial.print("\n");                    // goes to next line
  
	delay(1000);                           //gives a delay of 1000ms

}
 


int readTemp()                         // get the temperature and convert it to celsius

{
  
	temp = analogRead(tempPin);
	return temp * 0.48828125;

}