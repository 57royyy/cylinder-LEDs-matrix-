# cylinder-LEDs-matrix-

Here is the electronic sketch of this project

It shows how everything is linked: 
On the left there is the Arduino board which connect everything 
On the right there is the connector board, on which the four buttons are plugged in. Each one is connected to a pullout pin and to the ground on the arduino board.
At the bottom, there is a LEDs strips. In this scheme there are only 6 LEDs, but in the real project there are hundreds of them. So in the case where there are only few LEDs, we can connect the strip directly on the 5v pin, but with hundreds of LEDs we need external power supplies that are directly connected to the stripes. In this case the strips only need to be connected to the arduino board on a pin and on the ground

The amount of power needed has to be calculated depending on how many LEDs there are and on how much power each one requires. Those calculations give good indication to make sure to add enough power and avoid any problem

