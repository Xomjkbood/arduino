void setup() 
{
  Serial.begin(9600);
}
void loop()
{
  String statusbat;                                //переменная статуса батареи
  String simproc;
  float voltage = analogRead(A0) / 1024.0 * 9.0;   //значение 9.0 подбирается от номинала резисторного делителя 
  float vol = voltage * 100;                       
  int voltproc = map(vol, 270, 420, 0, 100);       //мапим полученые значения к процентам
  if (vol > 270) {
    statusbat = voltproc;
    simproc = " %";
  }
  else{
      statusbat = "Low Battery"; 
  }
  Serial.print(statusbat);
  Serial.println(simproc);
  Serial.print(voltage);
  Serial.println(" v");
  delay(1000);        
}
