# PhysicsPinball


## CONTROLS
- Left and right keys to move the pullers
- Down to push the spring
- F1 to show the colliders
- F2 to skip to the ending scene
- SPACE to spawn a ball into the position of the mouse

## COMBOS
### The game currently have two combos, one if you destroy all the gears on the right and the other is when you destroy all the gears on the left and hit the end of the tunnel

## FEATURES
- Amazing Jojo references
- Fast pinball gameplay
- 60 FPS even in a toaster
- Za worldo combo
- Ora ora

## BUGS
- The collisions not working properly, we changed the provided code with the correct one the collision solver was only sending the first object fixture to the OnCollision function.
- Frame rate limiter, we implemented a frame time limit on the main code in order to run at 60 FPS.
- Objects can't be destroyed on a callback function, we instead moved the objects.
- Death sensor beeing activated multyple times on collision, we deactivated the sensor once the ball collides with it then reactivated with a sensor on the spring tunnel.
- Side bumpers not working properly, since we couldn't solve that we decided that giving a random number to the force was a funny mechanic.
- Spring not colliding with the ball, unfortunally if the force bettween the ball and the spring is too high the ball just don't collide with the spring needing to restart the level
- Pullers not colliding with the ball, the same that happends with the spring but in the pullers. 

### Game made by 
- Victor Falcon
- Sofia Liles
- Laura Isidro

## Github Link
https://github.com/ZaroDev/PhysicsPinball

### Original Game
http://www.freewebarcade.com/game/extreme-pinball/

We took the layout of the game and trasnformed into a JJBA game
