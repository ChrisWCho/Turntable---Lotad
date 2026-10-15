# Turntable---Lotad
Reusing an old stepper motor to make a turntable.

I wanted to get a turntable to showcase some projects that I've worked on over the last couple of years.
But I remember I had some old unused components from my very first Arduino kit back in college.
The 28byj-48 stepper motor that comes with every Arduino kit.

This was just an idea in theory but to get it working I needed an micro controller.
Since this project was super simple, I just used an old Arduino Nano laying around.

I used the Arduino IDE to code it and it was a very quick and simple code for this project.
All we needed for the code was 3 buttons. One button for turning clockwise, another button for turning counter clockwise, and last but not least, a button for stopping.

After that we just needed the hardware and housing which was quickly designed on SolidWorks and we have a working model.

Although hard to see in the video, the plate is turning cw, ccw, and stopping.

https://github.com/user-attachments/assets/02181aaa-95ed-48e9-bb1c-e30980d72fd3

# Here is an example displaying my previous project.

https://github.com/user-attachments/assets/c1656fa2-e577-4fdd-bf91-4218da624918

So, here is where  I went for a redesign in CAD, It wasn't until after this moment that I had an idea for this housing.
The Pokémon Lotad. Here's the CAD.
<img width="2384" height="1304" alt="image" src="https://github.com/user-attachments/assets/82ccad62-414f-44db-bba1-19ba9be7b985" />

# This is the printed design.
<img width="3072" height="4080" alt="PXL_20260919_070045899 MP" src="https://github.com/user-attachments/assets/333b0c59-3959-4101-8495-d000145f2258" />

# I had some keyboard switches laying around so I designed them into the project.
I designed the buttons on the eyes and mouth for the rotation control.
<img width="4080" height="3072" alt="PXL_20260919_201237026" src="https://github.com/user-attachments/assets/a78339b3-0305-4d1e-b02c-3d3f2d5aead8" />

So despite being a simple project, there were some moving parts to it, I had to do some soldering to get all the connections together as well as powering everything.
So the 28byj-48 stepper motor I have is the 5V module. so it needs an external power source that isn't produced from the Arduino board.
But the Arduino nano's Vin pin has to be powered with voltages 7V to 12V. With research, there is a work around on this.
We connect the power source to the Arduinos 5V pin. This allows the Arduino to be powered as well as powering the 28byj-48 stepper motor from one power source.

So now we get to the power source and how I will be powering it for this project.
I am using a rechargable 2000mAh LiPo batter that produces 3.7V. Which is under the required 5V.
To get to the desired output I am using a battery module LX-LCBST that allows the battery to be charged through usb-c and is a step-up converter that takes the 3.7V as an input and output the required 5V for this project.
The LX-LCBST PCB uses the same charging board circuit as the tp4056 charging module, and adds a step up converter to it all on one PCB.

*** It is important to note that since it uses the tp4056 charging module, we cannot charge and use (turn on) the turntable at the same time as it does not have load sharing capabilities. ***

So one issue that came up is fitting everything into one housing, the boards did not allow all boards to be placed horizontally, so I designed the housing to hold the boards vertically.
<img width="4080" height="3072" alt="PXL_20261015_042319954" src="https://github.com/user-attachments/assets/ffa47889-a26c-442a-ad90-e6794aaf5c7b" />

# The build in all its glory!
<img width="4080" height="3072" alt="PXL_20261015_042222826" src="https://github.com/user-attachments/assets/471201d1-d57f-47d1-8d95-9332bf161173" />

# Here is a clip of the Lotad Turntable.


https://github.com/user-attachments/assets/bc22b4db-4022-4623-8b66-c89eb8448cc5

# Now that it's done, we can finally use it for the intended purpose, displaying/showcasing old (and new) projects.

https://github.com/user-attachments/assets/953ed7cb-7a80-44d3-9546-92380ee8742b

https://github.com/user-attachments/assets/61bb3047-1e0a-4ca3-9b5e-39e7226cf842

https://github.com/user-attachments/assets/0ca8eeef-1e77-466e-b3df-4054d2c4a5c3

