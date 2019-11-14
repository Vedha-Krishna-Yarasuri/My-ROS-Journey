

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  n;

void messages( const std_msgs::String& directions){ 
  n.loginfo(directions.data);// blink the led
}

ros::Subscriber<std_msgs::String> sub("directions",&messages);

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
