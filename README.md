# limo_navi

```bash
# RUN limo gazebo
roslaunch limo_gazebo_sim limo_four_diff.launch

# MAKE map
roslaunch turtlebot3_slam turtlebot3_slam.launch 

# RUN limo navigation
roslaunch turtlebot3_navigation turtlebot3_navigation.launch 
```

```bash
# Build Dokcer
docker build -t user_set_docker_name:user_set_docker_tag .

# RUN Docker
docker run -it \
    --gpus all \
    --env="DISPLAY=$DISPLAY" \
    --env="NVIDIA_DRIVER_CAPABILITIES=all" \
    --env="NVIDIA_VISIBLE_DEVICES=all" \
    -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
    -v /home/username/.ssh:/root/.ssh \
    -v /home/usernanme/.gitconfig:/root/.gitconfig \
    --privileged \
    user_set_docker_name:user_set_docker_tag
```

![Image](https://github.com/user-attachments/assets/ee866f04-584f-4eb8-9691-f0932da7a010)
