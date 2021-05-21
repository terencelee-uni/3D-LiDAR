# 3D-LiDAR
**ECE 445 Senior Design Project**

![Animated Model](https://media.giphy.com/media/t0XBKgClR0BUU57slF/giphy.gif)

[![Demo Video]({https://imgur.com/a/gNEjre5})]({https://www.youtube.com/watch?v=dHrQx4oeLag} "ECE 445 Demo")
[Demo Video](https://www.youtube.com/watch?v=dHrQx4oeLag)

Team Members: Xizheng Fang, Terence Lee, Jamie Xu

Since the introduction of the autopilot feature by Tesla in 2016, there has been an explosive interest in autonomous driving. Many companies have since spent large amounts of resources and manpower in this profitable field, especially in the research of 3D Light Detection and Ranging (LiDAR) sensors, one of the more vital aspects of self-driving vehicles (along with countless applications in surveying, movie special effects, sim racing, etc.) This device is utilized to collect the data of a vehicle’s surroundings and output an accurate 3D point cloud map so the vehicle can avoid obstacles accordingly. Because of the growth in popularity of autonomous vehicles, the interest in 3D LiDAR sensors has seen a similar increase among enthusiasts and hobbyists. However, unlike big corporations that could obtain industry-grade LiDAR technology for years, individuals typically cannot afford the high cost of entry for a 3D LiDAR sensor. To make it easier for hobbyists to explore the self-driving vehicle field, we are developing a system that will provide similar functionalities as the current 3D LiDAR industry solutions utilizing 1D time-of-flight (ToF) sensors while also remaining both affordable and easily obtainable.

The system built is aimed towards the hobbyist market which has been largely neglected by the market up until now. The solution’s friendly cost of entry and relative ease of construction to be our main selling points. Instead of using typical single-phase or solid-state 3D LiDAR sensors which cost upwards of thousands of dollars, we build the system based on a ToF sensor (also called 1D LiDAR) that can be up to a hundredth of the cost. The sensor will scan the environment and perform distance measurements on a 2-axis platform with a stepper motor helping to rotate the sensor 360 degree on the platform. Meanwhile, another motor will pitch the sensor up and down so the sensor can scan its environments at various height levels. The recorded spherical coordinates of the measured area will then be converted into Cartesian coordinates and eventually exported as a point cloud file that can be visualized to show the scanned room.  
