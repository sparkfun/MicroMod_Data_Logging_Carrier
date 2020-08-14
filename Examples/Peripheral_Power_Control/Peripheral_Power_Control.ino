/*

*/

int headerCS = G0;
int peripheralPowerControl = G1;
int qwiicPowerControl = G2;

#if defined(ARDUINO_ARCH_APOLLO3)

#elif defined(__IMXRT1062__)

#endif

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(headerCS, OUTPUT);
  pinMode(peripheralPowerControl, OUTPUT);
  pinMode(qwiicPowerControl, OUTPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(headerCS, HIGH);
  peripheralPowerOn();
  qwiicPowerOn();
  delay(2000); 
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(headerCS, LOW);
  peripheralPowerOff();
  qwiicPowerOff();
  delay(2000);
}

//Qwiic connector power is controlled from P-channel MOSFET so logic is reversed
void qwiicPowerOn()
{
  digitalWrite(qwiicPowerControl, LOW);
}
void qwiicPowerOff()
{
  digitalWrite(qwiicPowerControl, HIGH);
}

//3V3 peripheral power is controlled from P-channel MOSFET so logic is reversed
void peripheralPowerOn()
{
  digitalWrite(peripheralPowerControl, LOW);
}
void peripheralPowerOff()
{
  digitalWrite(peripheralPowerControl, HIGH);
}
