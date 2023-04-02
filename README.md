# IMGD4000: Agent-based Simulation Assignment

Programming assignment for implementing a boids swarm algorithm, created for IMGD 4000.
Gameplay Video: https://clipchamp.com/watch/XhdourpqDyE

## Additional Implemented Rule: Goal Setting

The swarm now follows a fourth rule: attempting to move toward a goal agent in the game world that is moving in constant circular motion, with its motion started and stopped by the player.

By spawning in a Blueprint Asset through C++, the FlockingManager maintains a reference to the Goal_BP instance, and is capable of slightly adjusting the swarm velocity towards the object every update. This added rule now gives the boid swarm behavior as if they were attempting to following the moving orange ball. If no Goal is specified in the FlockingGameMode_BP instance, then this rule will be ignored by the swarm, as no Goal will be spawned in or exist.

The player can pause or resume the circular motion of the ball at any time by pressing the Space key. 