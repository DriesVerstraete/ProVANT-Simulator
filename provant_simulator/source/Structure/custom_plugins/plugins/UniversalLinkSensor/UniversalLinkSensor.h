#include <ros/ros.h>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/TransportTypes.hh>
#include <gazebo/common/Time.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/common/Events.hh>
#include <update_timer.h>
#include <iostream>
#include <boost/thread.hpp>
#include <ros/callback_queue.h>
#include <random>
#include "XMLRead.h"
#include "simulator_msgs/Sensor.h"

// testes
#include <boost/date_time.hpp>
#include "std_msgs/String.h"

#include <ros/package.h>
#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::xml;
using namespace log4cxx::helpers;

namespace gazebo
{

	
	class UniversalLinkSensor : public ModelPlugin
	{

		public: UniversalLinkSensor(); 
  		public:virtual ~UniversalLinkSensor(); 
		public:virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf); 
  		public: virtual void Reset();  
  		protected: virtual void Update(); 
		

		private:  
			
			std::string NameOfJointR_;
			std::string NameOfJointL_;
			std::string NameOfNode_;
			std::string link_name_;
			physics::LinkPtr link;
			physics::WorldPtr world; 
			physics::JointPtr juntaR;
			physics::JointPtr juntaL;   
			UpdateTimer updateTimer;
  			event::ConnectionPtr updateConnection;
			ros::NodeHandle node_handle_;
			boost::mutex lock;
			ros::Publisher publisher_;	
			

	};
}
