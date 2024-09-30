const int soil_moisture_pin = A5;  /* Soil moisture sensor O/P pin */
const int water_pump_pin = 6;

void setup() 
{
  pinMode(water_pump_pin , OUTPUT);
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(soil_moisture_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  if (moisture_percentage < 25)
  {
    digitalWrite(water_pump_pin , HIGH);
    delay(10000);
  }
  if (moisture_percentage >+ 50)
  {
    digitalWrite(water_pump_pin , LOW);
  }
//  Serial.print("Moisture Percentage = ");
//  Serial.print(moisture_percentage);
//  Serial.print("%\n\n");
//  delay(1000);
}
