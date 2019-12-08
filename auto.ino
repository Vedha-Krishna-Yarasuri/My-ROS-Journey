

#include <ros.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle  n;
float x;

int motorpin1=2;
int motorpin2=3;
int motorpin3=4;
int motorpin4=5;

void messages(geometry_msgs::Twist& husky){
  n.loginfo("I am here"); 
  x= float(husky.linear.x);
    if(x==1.8){
      n.loginfo("I am here");
      digitalWrite(motorpin1,HIGH);
      digitalWrite(motorpin3,HIGH);
      digitalWrite(motorpin2,LOW);
      digitalWrite(motorpin4,LOW);
    }
    else{
      n.loginfo("I am  not here");
      }
//  n.loginfo(x);
//  n.loginfo(directions.data);// blink the led
}

ros::Subscriber<geometry_msgs::Twist> sub("husky",&messages);

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
