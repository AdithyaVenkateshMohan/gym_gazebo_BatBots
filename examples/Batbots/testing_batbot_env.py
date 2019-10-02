#!/usr/bin/env python
import gym
from gym import wrappers
import gym_gazebo
import time
import numpy
import random
import time


if __name__ == "__main__":
    env = gym.make('GazeboBATBot_Sonar-v0')
    print('success in creating env for the batbots')
    i=0
    while i < 100:
        action = 1
        observation, reward, done, info = env.step(action)
        action = 2
        observation, reward, done, info = env.step(action)
        i+=1