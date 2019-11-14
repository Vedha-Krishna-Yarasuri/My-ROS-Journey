

#include <ros.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle  n;

void messages( const geometry_msgs::Twist& husky){
  n.loginfo("I am here"); 
//  n.loginfo(directions.data);// blink the led
}

ros::Subscriber<geometry_msgs::Twist> sub("husky",&messages);

void setup()
{ 
  n.initNode();
  n.subscribe(sub);
}

void loop()
{  
  n.spinOnce();
  delay(1);
}
