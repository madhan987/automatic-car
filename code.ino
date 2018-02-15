#define LM1  5     // left motor
#define LM2 6      // left motor
#define RM1 13     // right motor
#define RM2 7      //right motor

//ultrasonic sensor

const int obstacle = 17;
const int no_obstacle =16;
float cm;

//IR sensor
int isObstaclePin1 = 10;  // This is our input pin of left ir sensor
int isObstacle1 = HIGH;  // HIGH MEANS NO OBSTACLE


int isObstaclePin2 = 4;  // This is our input pin of right ir sensor
int isObstacle2 = HIGH; // HIGH MEANS NO OBSTACLE

void setup()
{
  Serial.begin(9600);
  pinMode(obstacle, OUTPUT);
  pinMode(no_obstacle, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(isObstaclePin1, INPUT);
  pinMode(isObstaclePin2, INPUT);
  Serial.begin(9600);
    
}

void loop()
{
  digitalWrite(obstacle, LOW);       
  delayMicroseconds(2);
  digitalWrite(obstacle, HIGH);
  delayMicroseconds(2);
  cm = pulseIn(no_obstacle, HIGH) / 58.0; //The echo time is converted into cm
  cm = (int(cm * 100.0)) / 100.0;     //Keep two decimal places

  isObstacle1 = digitalRead(isObstaclePin1);
  isObstacle2 = digitalRead(isObstaclePin2);

    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);

 //ultrasonic sensor check-up
    //if there is a obstacle within 40cm,car automatically stops.
    if(cm<40)
    {
    Serial.print(cm);
    Serial.print("car is approaching");
    Serial.println();
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
   }
  
  //if there is no obstacle move straight
  else
    {
    Serial.print("safe driving");
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }
//ir sensor check-up
  //if there is a obstacle in left side,it will move right
     if(isObstacle1 == LOW)
    { 
    Serial.print("car is approaching");
    Serial.println();
    Serial.println("turning right-->right-->");  
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);  
    }
    
    //if there is a obstacle in right side,it will move left
    else if(isObstacle2 == LOW)
  { 
      Serial.print("car is approaching");
      Serial.println();
       Serial.println("turning <--left<--left");
       
           digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
      
    }
    //if there is no obstacle in either side move straight
    else
    { 
     delay(20);  
      Serial.print("safe driving");
        digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }

 }
