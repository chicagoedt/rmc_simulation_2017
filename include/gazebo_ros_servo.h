#ifndef GAZEBO_ROS_SERVO_HH
#define GAZEBO_ROS_SERVO_HH

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/QuaternionStamped.h>

#include <gazebo/physics/physics.hh>
#include <gazebo/transport/TransportTypes.hh>
#include <gazebo/common/Time.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/common/Events.hh>

#include <boost/thread.hpp>
#include <boost/bind.hpp>

namespace gazebo
{

   class GazeboRosServo : public ModelPlugin
   {
      /// \brief Constructor
      public: GazeboRosServo();

      /// \brief Destructor
      public: virtual ~GazeboRosServo();

      /// \brief Load the controller
      public: void Load( physics::ModelPtr _parent, sdf::ElementPtr _sdf );

      /// \brief Update the controller
      //protected: virtual void UpdateChild();
      public:  void OnUpdate(const common::UpdateInfo & _info);

   private:
      physics::ModelPtr _model;
      event::ConnectionPtr updateConnection;

      ros::NodeHandle* rosnode_;
      ros::Publisher servoRotationPub_;
      ros::Subscriber sub_;
      tf::TransformBroadcaster *transform_broadcaster_;
      tf::TransformListener* transform_listener_;

      physics::JointPtr _servoJoint;

      common::Time pastTime;
      float timeInc;

      const float frequencyUpdate = 1;

   };

}

#endif
