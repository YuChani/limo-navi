#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt

def load_path(file_path):
    x_vals, y_vals = [], []
    with open(file_path, 'r') as file:
        for line in file:
            if line.strip() and not line.startswith("---"):
                parts = line.strip().split()
                if len(parts) == 2:
                    x, y = map(float, parts)
                    x_vals.append(x)
                    y_vals.append(y)
    return x_vals, y_vals

# file path
odom_path_file = "/root/catkin_ws/bag_to_txt/odom_path_log.txt"
nav_path_file = "/root/catkin_ws/bag_to_txt/path_log.txt"


odom_x, odom_y = load_path(odom_path_file)
nav_x, nav_y = load_path(nav_path_file)


plt.figure(figsize = (8, 6))
plt.plot(odom_x, odom_y, label = 'Odometry', color = 'blue')
plt.plot(nav_x, nav_y, label = 'Global', color='red', linestyle = '--')

plt.title("Path")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.grid(True)
plt.axis('equal')
plt.tight_layout()
plt.show()
