/*
 * Copyright (C) 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include "gazebo/gazebo.hh"
#include "gazebo/common/common.hh"
#include "gazebo/msgs/msgs.hh"
#include "gazebo/physics/physics.hh"
#include "gazebo/transport/transport.hh"
#include "collision_map_request.pb.h"
#include <boost/shared_ptr.hpp>
#include <gazebo/gazebo_client.hh>

#include <iostream>

typedef const boost::shared_ptr<
  const collision_map_creator_msgs::msgs::CollisionMapRequest>
    CollisionMapRequestPtr;

/////////////////////////////////////////////////
// Function is called everytime a message is received.
void cb(CollisionMapRequestPtr &_msg)
{
  std::cout << "Message received"<<std::endl;
}

/////////////////////////////////////////////////
int main(int _argc, char **_argv)
{
  // Load gazebo
  gazebo::client::setup(_argc, _argv);

  // Create our node for communication
  gazebo::transport::NodePtr node(new gazebo::transport::Node());
  node->Init();

  // Listen to Gazebo world_stats topic
  gazebo::transport::SubscriberPtr sub = node->Subscribe("~/collision_map/command", cb);
  
  int counter=0;
  // Busy wait loop...replace with your own code as needed.
  while (true){
    gazebo::common::Time::MSleep(10);
    
  }

  // Make sure to shut everything down.
  gazebo::client::shutdown();
}
