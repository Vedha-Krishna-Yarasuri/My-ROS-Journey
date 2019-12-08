

#include <ros.h>
#include <std_msgs/String.h>
#include<string.h>
ros::NodeHandle  n;
int motorpin1=2;
int motorpin2=3;
int motorpin3=4;
int motorpin4=5;
char x[100];
void messages( const std_msgs::String& directions){ 
  n.loginfo(directions.data);// blink the led
  strcpy(x,directions.data);
    n.loginfo(strcmp(x,"f"));// blink the led

  if(directions.data=='b'){
    n.loginfo("I am here");
      digitalWrite(motorpin1,HIGH);
      digitalWrite(motorpin3,HIGH);
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin4,LOW);
    }
  else if(directions.data=="b"){
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin3,LOW);
      digitalWrite(motorpin2,HIGH);
      digitalWrite(motorpin4,HIGH);
    }
  else if(directions.data=="r"){
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin3,HIGH);
      digitalWrite(motorpin2,HIGH);
      digitalWrite(motorpin4,LOW);
    }
  else if(directions.data=="l"){
      digitalWrite(motorpin1,HIGH);
      digitalWrite(motorpin3,LOW);
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin4,HIGH);
    }
  else{
    n.loginfo("I am not here");
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin3,LOW);
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin4,LOW);
    }
}

ros::Subscriber<std_msgs::String> sub("directions",&messages);

void setup()
{ 
   n.initNode();
   n.subscribe(sub);
   pinMode(motorpin1,OUTPUT);
   pinMode(motorpin3,OUTPUT);
   pinMode(motorpin2,OUTPUT);
   pinMode(motorpin4,OUTPUT);
}

void loop()
{  
  n.spinOnce();
  delay(1);
}
