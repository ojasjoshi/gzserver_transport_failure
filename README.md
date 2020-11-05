# Prereq:
- Checkout gazebo9.13 branch
- Add following to TopicManager
```bash
//////////////////////////////////////////////////
void TopicManager::clearAdvertisedTopics(){
  this->advertisedTopics.clear();
}
```
- Build gazebo

# Build
> cd <path-to-repo> 
> make 

# Run
In separate terminals run,
> gzserver

> <path-to-repo>/build/request_publisher "(-10,10)(10,10)(10,-10)(-10,-10)" 10 0.01 ~/map.png

> <path-to-repo>/collision_map_creator_plugin/build/request_subscriber

- On successful execution you should see the following exception:
```bash
request_publisher: /usr/include/boost/smart_ptr/shared_ptr.hpp:734: typename boost::detail::sp_member_access<T>::type boost::shared_ptr<T>::operator->() const [with T = gazebo::transport::Publication; typename boost::detail::sp_member_access<T>::type = gazebo::transport::Publication*]: Assertion `px != 0' failed.
```