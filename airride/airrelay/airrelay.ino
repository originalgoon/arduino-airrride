#define RELAY1 22                         
#define RELAY2 23                       
#define RELAY3 24                       
#define RELAY4 25
#define RELAY5 26
#define RELAY6 27
#define RELAY7 28
#define RELAY8 29
#define RELAY9 30
#define RELAY10 31
#define RELAY11 32
#define RELAY12 33
#define RELAY13 34
#define RELAY14 35
#define RELAY15 36
#define RELAY16 37


int led = 13;
int cycle0 = 0;
int cycle1 = 0;
int cycle2 = 0;
int ignState = 0;
int lfState = 0;
int rfState = 0;
int lrState = 0;
int rrState = 0;
int preSet0 = 0;
int preSet1 = 0;
int preSet2 = 0;
const int ignPin = 38;
const int psetPin0 = 39;
const int psetPin1 = 40;
const int psetPin2 = 41;
const int rhS0 = 0;
const int rhS1 = 1;
const int rhS2 = 2;
const int rhS3 = 3;

void setup()
{
pinMode(rhS0,INPUT);
pinMode(rhS1,INPUT);
pinMode(rhS2,INPUT);
pinMode(rhS3,INPUT);
pinMode(psetPin0,INPUT);
pinMode(psetPin1,INPUT);
pinMode(psetPin2,INPUT);
preSet0 = digitalRead(psetPin0);
preSet1 = digitalRead(psetPin1);
preSet2 = digitalRead(psetPin2);
pinMode(led,OUTPUT);
pinMode(ignPin,INPUT);
lfState = digitalRead(rhS0);
rfState = digitalRead(rhS1);
lrState = digitalRead(rhS2);
rrState = digitalRead(rhS3);
ignState = digitalRead(ignPin);
pinMode(RELAY1, OUTPUT);		//AIR LEFT FRONT LIFT
pinMode(RELAY2, OUTPUT);		//AIR RIGHT FRONT LIFT
pinMode(RELAY3, OUTPUT);		//AIR LEFT REAR LIFT
pinMode(RELAY4, OUTPUT);		//Arduino power latch (I)
pinMode(RELAY5, OUTPUT);		//AIR RIGHT REAR LIFT
pinMode(RELAY6, OUTPUT);		//AIR LEFT FRONT DUMP
pinMode(RELAY7, OUTPUT);		//AIR RIGHT FRONT DUMP
pinMode(RELAY8, OUTPUT);		//AIR LEFT REAR DUMP
pinMode(RELAY9, OUTPUT);		//AIR RIGHT REAR DUMP
pinMode(RELAY10, OUTPUT);
pinMode(RELAY11, OUTPUT);	//WATERMETH PUMP
pinMode(RELAY12, OUTPUT);	//WATERMETH SOLENOID
pinMode(RELAY13, OUTPUT);
pinMode(RELAY14, OUTPUT);
pinMode(RELAY15, OUTPUT);
pinMode(RELAY16, OUTPUT);
digitalWrite(RELAY1,HIGH);// Turns Relay Off       
digitalWrite(RELAY2,HIGH);// Turns Relay Off
digitalWrite(RELAY3,HIGH);// Turns Relay Off
digitalWrite(RELAY4,LOW);// This is a the power relay latch, Only set to HIGH for power off state.
digitalWrite(RELAY5,HIGH);// Turns Relay Off
digitalWrite(RELAY6,HIGH);// Turns Relay Off
digitalWrite(RELAY7,HIGH);// Turns Relay Off
digitalWrite(RELAY8,HIGH);// Turns Relay Off
digitalWrite(RELAY9,HIGH);// Turns Relay Off
digitalWrite(RELAY10,HIGH);// Turns Relay Off
digitalWrite(RELAY11,HIGH);// Turns Relay Off
digitalWrite(RELAY12,HIGH);// Turns Relay Off
digitalWrite(RELAY13,HIGH);// Turns Relay Off
digitalWrite(RELAY14,HIGH);// Turns Relay Off
digitalWrite(RELAY15,HIGH);// Turns Relay Off
digitalWrite(RELAY16,HIGH);// Turns Relay Off

}

void loop()
{
  
  while(ignState==1)
	{
    ignState = digitalRead(ignPin);
if (preSet0 == 1){
    rideHeight();
}
if (preSet1 == 1){
slamMed();
}
if (preSet2 == 1){
donK();
}
	}
  if (ignState==0)// IF statement for ignition being turned off
  {
digitalWrite(RELAY6,LOW);
digitalWrite(RELAY7,LOW);  
digitalWrite(RELAY8,LOW);  
digitalWrite(RELAY9,LOW);  
      delay(6000);
      digitalWrite(RELAY4,HIGH); //arduino shutoff
  }
}

void rideHeight(){
lfState = digitalRead(rhS0);	//LEFT FRONT RIDE HIGHT SENSOR
rfState = digitalRead(rhS1);	//RIGHT FRONT RIDE HIGHT SENSOR
lrState = digitalRead(rhS2);	//LEFT REAR RIDE HEIGHT SENSOR
rrState = digitalRead(rhS3);	//RIGHT REAR RIDE HEIGHT SENSOR
cycle0++;
	if (lfState< 200){
		digitalWrite (RELAY1,LOW);
		digitalWrite (RELAY6,HIGH);
}
		else {
			digitalWrite (RELAY1,HIGH);
			digitalWrite (RELAY6,HIGH);
}
	if (lfState > 300){
		digitalWrite (RELAY6,LOW);
		digitalWrite (RELAY1,HIGH);
}
		else {
			digitalWrite (RELAY1,HIGH);
			digitalWrite (RELAY6,HIGH);
}
	if (rfState < 200){
		digitalWrite (RELAY2,LOW);
		digitalWrite (RELAY7,HIGH);
}
		else {
			digitalWrite (RELAY2,HIGH);
			digitalWrite (RELAY7,HIGH);
}
	if (rfState > 300){
		digitalWrite (RELAY7,LOW);
		digitalWrite (RELAY2,HIGH);
}
		else {
			digitalWrite (RELAY2,HIGH);
			digitalWrite (RELAY7,HIGH);
}
	if (lrState < 200){
		digitalWrite (RELAY3,LOW);
		digitalWrite (RELAY8,HIGH);
}
		else {
			digitalWrite (RELAY3,HIGH);
			digitalWrite (RELAY8,HIGH);
}
	if (lrState > 300){
		digitalWrite (RELAY8,LOW);
		digitalWrite (RELAY3,HIGH);
}
		else {
			digitalWrite (RELAY3,HIGH);
			digitalWrite (RELAY8,HIGH);
}
	if (rrState < 200){
		digitalWrite (RELAY5,LOW);
		digitalWrite (RELAY9,HIGH);
}
		else {
			digitalWrite (RELAY5,HIGH);
			digitalWrite (RELAY9,HIGH);
}
	if (rrState > 300){
		digitalWrite (RELAY9,LOW);
		digitalWrite (RELAY5,HIGH);
}
		else {
			digitalWrite (RELAY5,HIGH);
			digitalWrite (RELAY9,HIGH);
}

void slamMed(){
lfState = digitalRead(rhS0);	//LEFT FRONT RIDE HIGHT SENSOR
rfState = digitalRead(rhS1);	//RIGHT FRONT RIDE HIGHT SENSOR
lrState = digitalRead(rhS2);	//LEFT REAR RIDE HEIGHT SENSOR
rrState = digitalRead(rhS3);	//RIGHT REAR RIDE HEIGHT SENSOR
cycle1++;
	if (lfState< 100){
		digitalWrite (RELAY1,LOW);
		digitalWrite (RELAY6,HIGH);
}
		else {
			digitalWrite (RELAY1,HIGH);
			digitalWrite (RELAY6,HIGH);
}
	if (lfState > 200){
		digitalWrite (RELAY6,LOW);
		digitalWrite (RELAY1,HIGH);
}
		else {
			digitalWrite (RELAY1,HIGH);
			digitalWrite (RELAY6,HIGH);
}
	if (rfState < 100){
		digitalWrite (RELAY2,LOW);
		digitalWrite (RELAY7,HIGH);
}
		else {
			digitalWrite (RELAY2,HIGH);
			digitalWrite (RELAY7,HIGH);
}
	if (rfState > 200){
		digitalWrite (RELAY7,LOW);
		digitalWrite (RELAY2,HIGH);
}
		else {
			digitalWrite (RELAY2,HIGH);
			digitalWrite (RELAY7,HIGH);
}
	if (lrState < 100){
		digitalWrite (RELAY3,LOW);
		digitalWrite (RELAY8,HIGH);
}
		else {
			digitalWrite (RELAY3,HIGH);
			digitalWrite (RELAY8,HIGH);
}
	if (lrState > 200){
		digitalWrite (RELAY8,LOW);
		digitalWrite (RELAY3,HIGH);
}
		else {
			digitalWrite (RELAY3,HIGH);
			digitalWrite (RELAY8,HIGH);
}
	if (rrState < 100){
		digitalWrite (RELAY5,LOW);
		digitalWrite (RELAY9,HIGH);
}
		else {
			digitalWrite (RELAY5,HIGH);
			digitalWrite (RELAY9,HIGH);
}
	if (rrState > 200){
		digitalWrite (RELAY9,LOW);
		digitalWrite (RELAY5,HIGH);
}
		else {
			digitalWrite (RELAY5,HIGH);
			digitalWrite (RELAY9,HIGH);
}

void donK(){
lfState = digitalRead(rhS0);	//LEFT FRONT RIDE HIGHT SENSOR
rfState = digitalRead(rhS1);	//RIGHT FRONT RIDE HIGHT SENSOR
lrState = digitalRead(rhS2);	//LEFT REAR RIDE HEIGHT SENSOR
rrState = digitalRead(rhS3);	//RIGHT REAR RIDE HEIGHT SENSOR
cycle2++;
	if (lfState< 400){
		digitalWrite (RELAY1,LOW);
		digitalWrite (RELAY6,HIGH);
}
		else {
			digitalWrite (RELAY1,HIGH);
			digitalWrite (RELAY6,HIGH);
}
	if (lfState > 500){
		digitalWrite (RELAY6,LOW);
		digitalWrite (RELAY1,HIGH);
}
		else {
			digitalWrite (RELAY1,HIGH);
			digitalWrite (RELAY6,HIGH);
}
	if (rfState < 400){
		digitalWrite (RELAY2,LOW);
		digitalWrite (RELAY7,HIGH);
}
		else {
			digitalWrite (RELAY2,HIGH);
			digitalWrite (RELAY7,HIGH);
}
	if (rfState > 500){
		digitalWrite (RELAY7,LOW);
		digitalWrite (RELAY2,HIGH);
}
		else {
			digitalWrite (RELAY2,HIGH);
			digitalWrite (RELAY7,HIGH);
}
	if (lrState < 400){
		digitalWrite (RELAY3,LOW);
		digitalWrite (RELAY8,HIGH);
}
		else {
			digitalWrite (RELAY3,HIGH);
			digitalWrite (RELAY8,HIGH);
}
	if (lrState > 500){
		digitalWrite (RELAY8,LOW);
		digitalWrite (RELAY3,HIGH);
}
		else {
			digitalWrite (RELAY3,HIGH);
			digitalWrite (RELAY8,HIGH);
}
	if (rrState < 400){
		digitalWrite (RELAY5,LOW);
		digitalWrite (RELAY9,HIGH);
}
		else {
			digitalWrite (RELAY5,HIGH);
			digitalWrite (RELAY9,HIGH);
}
	if (rrState > 600){
		digitalWrite (RELAY9,LOW);
		digitalWrite (RELAY5,HIGH);
}
		else {
			digitalWrite (RELAY5,HIGH);
			digitalWrite (RELAY9,HIGH);
}
