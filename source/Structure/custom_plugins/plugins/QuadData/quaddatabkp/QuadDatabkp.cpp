/*
* File: QuadData
* Author: Jonatan Mota Campos
* Project: ProVANT
* Company: Federal University of Minas Gerais
* Version: 1.0
* Date: 13/02/19
* Description:  This library is responsable to implement a sensor that return for a Quadrotor all data of the folowing state space:

- x,y,z,roll,pitch,yaw,dx,dy,dz,droll,dpitch,dyaw

*/


#include <QuadData.h>


namespace gazebo
{
	// constructor
	QuadData::QuadData()
	{ 
				
	}

	// destructor
	QuadData::~QuadData()
	{	
		try
		{
			updateTimer.Disconnect(updateConnection);
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		} 
	}

	// initial setup
	void QuadData::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
	{	
		try
		{
			std::cout << "entrei Quad Estados plugin"<<std::endl;
	    		if (!ros::isInitialized())
	    		{
				ROS_INFO("Nao inicializado!");
	      		        return;
	    		}
			
			NameOfNode_ = XMLRead::ReadXMLString("NameOfTopic",_sdf); // Get name of topic to publish data
			NameOfJointR_ = XMLRead::ReadXMLString("NameOfJointR",_sdf); // name of the right joint
			NameOfJointL_ = XMLRead::ReadXMLString("NameOfJointL",_sdf); // name of the left joint
			
			world = _model->GetWorld();	// pointer to the world
			juntaR = _model->GetJoint(NameOfJointR_); // pointer to the right joint
			juntaL = _model->GetJoint(NameOfJointL_); // pointer to the left joint

			link_name_ = XMLRead::ReadXMLString("bodyName",_sdf); // name of the main body
			link = _model->GetLink(link_name_); // pointer to the main body			

			// notifying when occurs new step time
	  		Reset();
			updateTimer.Load(world, _sdf);
	  		updateConnection = updateTimer.Connect(boost::bind(&QuadData::Update, this));
			// ROS publisher
			publisher_ = node_handle_.advertise<simulator_msgs::Sensor>(NameOfNode_, 1);  //NameofNode é o nome do Topico na verdade
			
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	// reset
	void QuadData::Reset()
	{
		try
		{
			updateTimer.Reset();
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	// new step time
	void QuadData::Update()
	{
		try
		{
			boost::mutex::scoped_lock scoped_lock(lock); // mutex
			
			simulator_msgs::Sensor newmsg;
			newmsg.name = NameOfNode_;
			newmsg.header.stamp = ros::Time::now(); // time stamp
			newmsg.header.frame_id = "1";
			math::Pose pose = link->GetWorldPose();
			newmsg.values.push_back(pose.pos.x); // x
			newmsg.values.push_back(pose.pos.y); // y
			newmsg.values.push_back(pose.pos.z); // z
			newmsg.values.push_back(pose.rot.GetAsEuler( ).x); //roll
			newmsg.values.push_back(pose.rot.GetAsEuler( ).y); // pitch
			newmsg.values.push_back(pose.rot.GetAsEuler( ).z); // yaw
			math::Vector3 linear = link->GetWorldLinearVel();
			newmsg.values.push_back(linear.x); // dx
			newmsg.values.push_back(linear.y); // dy
			newmsg.values.push_back(linear.z); //dz
			math::Vector3 angular = link->GetWorldAngularVel( );
			// droll -> attention! we receive angular velocity, but we want to publish the derivative of euler angle
			double phi = pose.rot.GetAsEuler().x;
			double theta = pose.rot.GetAsEuler().y;
			double psi = pose.rot.GetAsEuler().z;
			double p = angular.x;
			double q = angular.y;
			double r = angular.z;
			newmsg.values.push_back(p + q*sin(phi)*tan(theta) + r*cos(phi)*tan(theta)); 
			 // dpitch  -> attention! we receive angular velocity, but we want to publish the derivative of euler angle
			newmsg.values.push_back(0 + q*cos(phi) - r*sin(phi));    
			// dyaw -> attention! we receive angular velocity, but we want to publish the derivative of euler angle
			newmsg.values.push_back(0 + q*sin(phi)*(1/cos(theta)) + r*cos(phi)*(1/cos(theta)));
			
			
			// publish data
			publisher_.publish(newmsg);					
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
			
			

			

	GZ_REGISTER_MODEL_PLUGIN(QuadData)
}
