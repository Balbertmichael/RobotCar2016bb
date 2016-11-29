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

int differenceThreshold = 40;

int DISTANCESENSOR_THRESHOLD = 100;
int REDLINE_THRESHOLD = 200

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
  int leftPhoto = analogRead(LEFTPHOTO);
  int rightPhoto = analogRead(RIGHTPHOTO);
  int centerPhoto = analogRead(CENTERPHOTO);
  int LEFTDISTANCEREADING = analogRead(LEFTDISTANCE);
  int RIGHTDISTANCEREADING = analogRead(RIGHTDISTANCE);
  int CENTERDISTANCEREADING = analogRead(CENTERDISTANCE);
	 
  if (centerPhoto > REDLINE_THRESHOLD) {RIGHTLINEDETECTED = 1; }
	
  int LEFTDISTANCEDIGITAL = 0;							//Same process for distance sensor readings
  if (LEFTDISTANCEREADING > DISTANCESENSOR_THRESHOLD) { LEFTDISTANCEDIGITAL = 1; }
  int RIGHTDISTANCEDIGITAL = 0;
  if (RIGHTDISTANCEREADING > DISTANCESENSOR_THRESHOLD) { RIGHTDISTANCEDIGITAL = 1; }
  int CENTERDISTANCEDIGITAL = 0;
  if (CENTERDISTANCEREADING > DISTANCESENSOR_THRESHOLD) { CENTERDISTANCEDIGITAL = 1; }
  

  if (CENTERDISTANCEDIGITAL == 1) {		//This checks for a reading from any of the distance sensors
	stopMotion();
  } else if (LEFTDISTANCEDIGITAL == 1 || RIGHTDISTANCEDIGITAL == 1) {
	if (REDLINEDETECTED == 1) {
		stopMotion();
	} else {
		forward();
	}	
  } else {   
	if (leftPhoto <= rightPhoto && centerPhoto <= leftPhoto && (max (rightPhoto, leftPhoto) - centerPhoto) > differenceThreshold) {
		forward();
	} else if (rightPhoto <= centerPhoto && rightPhoto <= leftPhoto && (max (centerPhoto, leftPhoto) - rightPhoto) > differenceThreshold) {
		turnRight();
	} else if (leftPhoto <= centerPhoto && rightPhoto <= leftPhoto && (max (centerPhoto, leftPhoto) - rightPhoto) > differenceThreshold {
		forward(); //not finished
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

