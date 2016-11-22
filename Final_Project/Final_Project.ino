#define LEFTPHOTO		//These analog input ports need to be defined!
#define RIGHTPHOTO
#define CENTERPHOTO
#define LEFTDISTANCE
#define RIGHTDISTANCE
#define CENTERDISTANCE 
#define LEFTOUTPUTA 5
#define LEFTOUTPUTB 6
#define RIGHTOUTPUTA 9
#define RIGHTOUTPUTB 10

int PHOTORESISTOR_THRESHOLD = 250;
int DISTANCESENSOR_THRESHOLD = 100;

void setup() {
  // put your setup code here, to run once:
  /*pinMode(LEFTPHOTO, INPUT);
  pinMode(RIGHTPHOTO, INPUT);
  pinMode(CENTERPHOTO, INPUT);
  pinMode(LEFTDISTANCE, INPUT);
  pinMode(RIGHTDISTANCE, INPUT);
  pinMode(CENTERDISTANCE, INPUT);*/
  pinMode(LEFTOUTPUTA, OUTPUT);
  pinMode(LEFTOUTPUTB, OUTPUT);
  pinMode(RIGHTOUTPUTA, OUTPUT);
  pinMode(RIGHTOUTPUTB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int LEFTPHOTOREADING = analogRead(LEFTPHOTO);
  int RIGHTPHOTOREADING = analogRead(RIGHTPHOTO);
  int CENTERPHOTOREADING = analogRead(CENTERPHOTO);
  int LEFTDISTANCEREADING = analogRead(LEFTDISTANCE);
  int RIGHTDISTANCEREADING = analogRead(RIGHTDISTANCE);
  int CENTERDISTANCEREADING = analogRead(CENTERDISTANCE);
  
  int LEFTPHOTODIGITAL = 0;							//Default value for all digital readings is 0
  if (LEFTPHOTOREADING > PHOTORESISTOR_THRESHOLD) LEFTPHOTODIGITAL = 1;		//but if analog value > threshold, change to 1
  int RIGHTPHOTODIGITAL = 0;
  if (RIGHTPHOTOREADING > PHOTORESISTOR_THRESHOLD) RIGHTPHOTODIGITAL = 1;
  int CENTERPHOTODIGITAL = 0;
  if (CENTERPHOTOREADING > PHOTORESISTOR_THRESHOLD) CENTERPHOTODIGITAL = 1;

  int LEFTDISTANCEDIGITAL = 0;							//Same process for distance sensor readings
  if (LEFTDISTANCEREADING > DISTANCESENSOR_THRESHOLD) LEFTDISTANCEDIGITAL = 1;
  int RIGHTDISTANCEDIGITAL = 0;
  if (RIGHTDISTANCEREADING > DISTANCESENSOR_THRESHOLD) RIGHTDISTANCEDIGITAL = 1;
  int CENTERDISTANCEDIGITAL = 0;
  if (CENTERDISTANCEREADING > DISTANCESENSOR_THRESHOLD) CENTERDISTANCEDIGITAL = 1;

	RIGHTDISTANCEDIGITAL == 1 ||
	CENTERDISTANCEDIGITAL == 1) {		//This checks for a reading from any of the distance sensors
	//Place code for distance-sensor-based behavior here
  } else {
	if (LEFTPHOTODIGITAL == 0) {
		turnLeft();
	} else if (RIGHTPHOTODIGITAL == 0) {
		turnRight();
	} else {
		forward();
	}
  }
}

void forward () {
    digitalWrite(LEFTOUTPUTA, HIGH);
    digitalWrite(RIGHTOUTPUTA, HIGH);
    digitalWrite(LEFTOUTPUTB, LOW);
    digitalWrite(RIGHTOUTPUTB, LOW);
}
void turnLeft () {
    digitalWrite(LEFTOUTPUTA, LOW);
    digitalWrite(RIGHTOUTPUTA, HIGH);
    digitalWrite(LEFTOUTPUTB, HIGH);
    digitalWrite(RIGHTOUTPUTB, LOW);
}
void turnRight () {
    digitalWrite(LEFTOUTPUTA, HIGH);
    digitalWrite(RIGHTOUTPUTA, LOW);
    digitalWrite(LEFTOUTPUTB, LOW);
    digitalWrite(RIGHTOUTPUTB, HIGH);
}
void stopMotion () {
    digitalWrite(LEFTOUTPUTA, LOW);
    digitalWrite(RIGHTOUTPUTA, LOW);
    digitalWrite(LEFTOUTPUTB, LOW);
    digitalWrite(RIGHTOUTPUTB, LOW);
}
}
