# C172 Pre-Flight Check

This program computes whether the weight and balance of a Cessna 172 (C172) are acceptable for flight.
lt prints overall aircraft weight, moment, and center of gravity, along with the result and an explanation for failure if any. 

Some assumptions and considerations that were made while creating this program:

Total aircraft weight is the sum of the empty aircraft weight, fuel, and payload, which includes passenger and cargo weights. Aircraft balance is computed by verifying that the moment and center of gravity are within the acceptable “Normal” flight envelope from the plots shown below. Moment can be computed by placing the payload weights at the stations shown in the loading arrrangements below. 

An empty airframe weight of 1431 lbs and an airframe center of gravity of 36.21 inches aft of the firewall was assumed.

![image](https://user-images.githubusercontent.com/70550648/109208973-d8ede580-775f-11eb-8e5b-b1b77ed92818.png)

Weight and balance information. Source: C172 flight manual

![image](https://user-images.githubusercontent.com/70550648/109209133-09358400-7760-11eb-9217-e4222cd74612.png)

![image](https://user-images.githubusercontent.com/70550648/109209205-1b172700-7760-11eb-9d10-4b0ea4db516d.png)

Weight and balance information. Source: C172 flight manual. The two graphs above represent the same information while showing different axis and units.
