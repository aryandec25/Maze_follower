/*Maze Follower*/

int trigPin1=4;
int echoPin1=5;
int trigPin2=2;
int echoPin2=3;
int motor_left[] = {8, 9};
int motor_right[] = {10, 11};


void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1,OUTPUT);          // Trigger Pin 1 
  pinMode(echoPin1,INPUT);           //Echo Pin 1
  pinMode(trigPin2,OUTPUT);          //Trigger Pin 2
  pinMode(echoPin2,INPUT);           //Echo Pin 2
  
  
  for(int i = 0; i < 2; i++)
    {
    pinMode(motor_left[i], OUTPUT);     //Ouput pins of the motors
    pinMode(motor_right[i], OUTPUT);
    }
}


void loop()
{
int dist1=distance1();
int dist2=distance2();

Serial.print("PING1 =");                   //Printing distance of PING 1.
Serial.println(dist1);
Serial.print("PING2 =");                  //Printing distance of PING 2.
Serial.println(dist2);
delay(500);



if(dist1>10 && dist2<28 )                   //Condition for Forward.
{  
 forward();
}

else if(dist2>28)                           //Condition for taking right
{
stop1();
delay(1000); 
right();
delay(490);
forward();
delay(700);
}

else if(dist1<10 && dist2<28)              //Condition for going left
{
 stop1();
 delay(1000);
 left();
 delay(490);
 forward();
 delay(500);
}

else if(dist1<10)                            //Condition for going left
{
stop1();
delay(1000);
left();
delay(490);
forward();
delay(500);
}

}



float distance1()                             //Function for Ping 1.
{
  float cm, time;
  digitalWrite(trigPin1,LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);
  
  
  time=pulseIn(echoPin1,HIGH);
  cm=(time/29)/2;
  return(cm);
  delay(100);
  
}


float distance2()                                 //Function for Ping 2.
{
  float cm, time;
  digitalWrite(trigPin2,LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  
  time=pulseIn(echoPin2,HIGH);
  cm=(time/29)/2;
  return(cm);
  delay(100);
  
}


void left()
  {
    digitalWrite(motor_left[0],HIGH);                              
    digitalWrite(motor_left[1],LOW); 
    digitalWrite(motor_right[0],LOW);//ANTICLOCKWISE
    digitalWrite(motor_right[1],HIGH); //clOCKWISE
    Serial.println("Left");                                         
  }



void right()
  {
    digitalWrite(motor_left[0],LOW);                              
    digitalWrite(motor_left[1],HIGH); 
    digitalWrite(motor_right[1],LOW);
    digitalWrite(motor_right[0],HIGH);    
    Serial.println("Right");              

     
  }
  
  void forward()
  {
    digitalWrite(motor_left[0],LOW);                             
    digitalWrite(motor_left[1],HIGH); 
    digitalWrite(motor_right[0],LOW);
    digitalWrite(motor_right[1],HIGH);
    Serial.println("Forward");          // This prints Forward when the robot would actually go forward.
    
  }
  void stop1()
  {
    digitalWrite(motor_left[0],LOW);                             
    digitalWrite(motor_left[1],LOW); 
    digitalWrite(motor_right[0],LOW);
    digitalWrite(motor_right[1],LOW);
    Serial.println("Stop");            // This Stops the bot  
  }

  void reverse()
  {
    digitalWrite(motor_left[0],HIGH);                             
    digitalWrite(motor_left[1],LOW); 
    digitalWrite(motor_right[0],HIGH);
    digitalWrite(motor_right[1],LOW);
    Serial.println("reverse");              //This is used when the bot is ordered to go back.
   }


