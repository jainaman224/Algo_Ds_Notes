### Introduction
The Haversine formulae is one among the most important and useful formula. 
It is used to calculate the shortest distance between two points on a sphere using their latitudes and longitudes measured along the surface. This way is used in tracking the various objects on earth and majorly used for navigation. The haversine can be expressed in trignometric function as:

                    haversine(θ)=sin^2(θ/2)

The haversine of the central angle which is (d/r) is calculated through the formulae:

     (d/r)=haversine(Φ2-Φ1) + cos(Φ1)cos(Φ2)haversine(λ2-λ1)

where,

	r=radius of the earth i.e. 6400Km
	d=distance between two points
	λ1,λ2=Longitude of the two points 
	θ1,θ2=Latitude of the two points
Through the above formula we can evaluate the value of d.

### Algorithm
1. Get the values of latitude and longitude of two points and the 'r' is constant(already known).
2. The angles must always be in radians.
3. Putting the values in the formula will directly give the value of the 'd'. 

### Pseudocode
dlon = lon2 - lon1 
dlat = lat2 - lat1 
a = (sin(dlat/2))^2 + cos(lat1) * cos(lat2) * (sin(dlon/2))^2 
c = 2 * atan2( sqrt(a), sqrt(1-a) ) 
d = R * c (where R is the radius of the Earth)

### Implementation:
Usage of the formula was done for the distance between Big Ben, London and Statue of Liberty and was calculated to be 5574.8 km.

### Limitation:
The formula is applicable to only exact spherical bodies. Hence, the estimated value is not exact as the formula assumes the Earth's surface to be sphere but the fact is earth is not a perfect sphere it is obalate spheroid.


### Time complexity
Best Case complexity = O(n)
Worst case complexity = O(n*n)

### References:
-community.esri.com
-Geeks for geeks




