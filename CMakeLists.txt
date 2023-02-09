cmake_minimum_required(VERSION 3.0.2)
project(my_turtle_controller)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  turtlesim
  geometry_msgs
)

catkin_package()
include_directories(${catkin_INCLUDE_DIRS})

add_executable(my_first_node src/my_first_node.cpp)
target_link_libraries(my_first_node ${catkin_LIBRARIES})

add_executable(my_second_node src/my_second_node.cpp)
target_link_libraries(my_second_node ${catkin_LIBRARIES})

add_executable(draw_circle src/draw_circle.cpp)
target_link_libraries(draw_circle ${catkin_LIBRARIES})

add_executable(draw_circle_cw src/draw_circle_cw.cpp)
target_link_libraries(draw_circle_cw ${catkin_LIBRARIES})

add_executable(my_turtle_pose_subscriber src/my_turtle_pose_subscriber.cpp)
target_link_libraries(my_turtle_pose_subscriber ${catkin_LIBRARIES})

add_executable(my_turtle_pose_control src/my_turtle_pose_control.cpp)
target_link_libraries(my_turtle_pose_control ${catkin_LIBRARIES})