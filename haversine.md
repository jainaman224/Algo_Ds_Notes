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

Implementation:
Usage of the formula was done for the distance between Big Ben, London and Statue of Liberty and was calculated to be 5574.8 km.
 
Limitation:
The formula is applicable to only exact spherical bodies. Hence, the estimated value is not exact as the formula assumes the Earth's surface to be sphere but the fact is earth is not a perfect sphere it is obalate spheroid.


// Java program for the haversine formula 

public class Haversine { 
static double haversine(double lat1, double lon1, 
                       double lat2, double lon2) 

    { 
        // distance between latitudes and longitudes 
        double dLat = Math.toRadians(lat2 - lat1); 
        double dLon = Math.toRadians(lon2 - lon1); 
  
        // convert to radians 
        lat1 = Math.toRadians(lat1); 
        lat2 = Math.toRadians(lat2); 
  
        // apply formulae 
        double a = Math.pow(Math.sin(dLat / 2), 2) +  
                   Math.pow(Math.sin(dLon / 2), 2) *  
                   Math.cos(lat1) *  
                   Math.cos(lat2); 
        double rad = 6371; 
        double c = 2 * Math.asin(Math.sqrt(a)); 
        return rad * c; 
    } 
  
    // Driver Code 
    public static void main(String[] args) 
    { 
        double lat1 = 51.5007; 
        double lon1 = 0.1246; 
        double lat2 = 40.6892; 
        double lon2 = 74.0445; 
        System.out.println(haversine(lat1, lon1, lat2, lon2) + " K.M."); 
    } 
}

// Output: 5574.840 km
