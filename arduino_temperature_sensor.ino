// Define the analog input pin for the thermistor
int ThermistorPin = A0;

// Declare variables to store values
int Vo;
float R1 = 10000;  // Resistance value of R1 in Ohms
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;  // Constants for Steinhart-Hart equation

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog input from the thermistor and calculate the resistance
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);

  // Calculate the temperature using the Steinhart-Hart equation
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;  // Convert temperature to Celsius
  Tf = (Tc * 9.0)/ 5.0 + 32.0;  // Convert temperature to Fahrenheit

  // Print the temperature in both Fahrenheit and Celsius
  Serial.print("Temperature: "); 
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");   

  // Add a delay to avoid spamming the serial monitor
  delay(500);
}
