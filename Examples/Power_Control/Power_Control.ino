/*

*/


#if defined(ARDUINO_ARCH_APOLLO3)

#elif defined(__IMXRT1062__)

#endif

int statLED = 13;

int headerCS = G0;
int peripheralPowerControl = G1;
int qwiicPowerControl = G2;

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

//Qwiic connector power is controlled from an LDO voltage regulator
void qwiicPowerOn()
{
  digitalWrite(qwiicPowerControl, HIGH);
}
void qwiicPowerOff()
{
  digitalWrite(qwiicPowerControl, LOW);
}

//3V3 peripheral power is controlled from an LDO voltage regulator
void peripheralPowerOn()
{
  digitalWrite(peripheralPowerControl, HIGH);
}
void peripheralPowerOff()
{
  digitalWrite(peripheralPowerControl, LOW);
}
