#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <Servo.h>

int servoPin = 9;
int angle = 45; // servo position in degrees 
Servo servo; 

ros::NodeHandle  nh;

void messageCb( const geometry_msgs::Twist& control_msg){
  angle += control_msg.angular.z;
  servo.write(angle);   
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb );

void setup()
{ 
  servo.attach(servoPin);
  servo.write(angle); 
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
