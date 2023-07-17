void setup() 
{
  Serial.begin(9600);
}
void loop()
{
  String lowbat;
  String simproc;
  float voltage = analogRead(A0) / 1024.0 * 9.0;
  float vol = voltage * 100;
  int voltproc = map(vol, 270, 420, 0, 100);
  if (vol > 270) {
      lowbat = voltproc;
      simproc = " %";
  }
  else{
      lowbat = "Low Battery"; 
  }
  Serial.print(lowbat);
  Serial.println(simproc);
  Serial.print(voltage);
  Serial.println(" v");
  delay(1000);        
}
