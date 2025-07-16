# Task: Temperature control on the rover

Background: This is program to monitor and control the internal temperature of an overworked robot. 
This robot has 'shield' mode, which will cool down and protect it from the heat, but since 'shield' mode is expensive,
we don't want it on all the time so we need to use communications method between nodes to minimize cost without overheating the robot

There will be a masters and a client;
- Where the master acts as the temperature signal, continously sending the internal temperature of the robot to the client
- The client receives the temperature change and once it reaches a certain temp, it'll activate 'shield' mode, reducing the temperature.