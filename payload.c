#include <stdio.h>
#include <math.h>

double input_func(char* text){
    double result;
    printf("Enter the %s: ", text);
    scanf("%lf", &result);

    if (result < 0){
        printf("Invalid entry. The %s is negative. \n", text);
        printf("Please try again!!\n");
        return input_func(text);
    }

    return result;
}

int preflight(){
    /* WEIGHTS */
    double empty_aircraft = 1431; //Weight of the empty aircraft (w/o payload and fuel)
    double pilot = input_func("weight of the pilot (in lbs)");
    
    while(pilot == 0){
        printf("The pilot weight (in lbs) is invalid, cannot be zero.\n");
        printf("Please try again!!\n");
        pilot = input_func("weight of the pilot (in lbs)");
    }

    double front_pax = input_func("weight of the front passenger (in lbs)");
    double rear_paxl = input_func("weight of the rear passenger on the left side (in lbs)");
    double rear_paxr = input_func("weight of the rear passenger on the right side (in lbs)");
    double rear_pax = rear_paxl + rear_paxr;

    /* Check if child seat is present or not. If not then it is baggage area 1 */
    int option1;
    printf("Is there a child seat? Press (1) for Yes and (0) for No: ");
    scanf("%d", &option1);

    double child_pax;
    double bag_area1;

    if(option1 == 1){
        child_pax = input_func("weight of child seat (in lbs)");
        bag_area1 = 0;
    }
    else{
        child_pax = 0;
        bag_area1 = input_func("weight in baggage area 1 aka front baggage area (in lbs)");
    }

    double bag_area2 = input_func("weight in baggage area 2 aka rear baggage area (in lbs)");

    double fuel_vol = input_func("total number of gallons of fuel");

    while(fuel_vol > 48 || fuel_vol == 0 || fuel_vol < 0){
        printf("Invalid entry for total fuel\n");
        printf("Either more than upper limit, or 0 or negative\n");
        printf("Please try again!!\n");
        fuel_vol = input_func("total number of gallons of fuel");
    }

    double fuel = fuel_vol * 6;

    /* Total weight of the aircraft */
    double total_weight = empty_aircraft + pilot + front_pax + rear_pax + 
                          child_pax + bag_area1 + bag_area2 + fuel;

    /* Moment due to each weight */
    // Moment arms are all in inches. Available on C172 flight manual
    //Fuel arm is set to 48 inches. Empty aircraft arm is set to 36.21 inches.
    double net_moment = (empty_aircraft * 36.21) + ((pilot + front_pax) * 37) + (rear_pax * 73) + 
                        (child_pax * 95) + (bag_area1 * 95) + (bag_area2 * 123) + (fuel * 48);

    /* Center of gravity */
    double cg = net_moment/total_weight;

    printf("Overall aicraft weight = %lf lbs\n", total_weight);
    printf("Center of gravity of the aircraft = %lf in\n", cg);
    printf("Overall moment = %lf lbs-in\n", net_moment);

    if (total_weight > 2300){
        printf("You cannot fly because your weight is outside of the normal operating envelop\n");
        return 0;
    }
    else if(cg < 35 || cg > 47.3 || total_weight > ((100*cg) - 1550) ){
        printf("You cannot fly because your moment is outside of the normal operating envelop\n");
        return 0;
    }
    else{
        printf("You are ready to fly... \n");
    }

}

int main(){

    int flight_status = preflight();

    if (flight_status == 0){
        printf("Oops we got a problem! :(\n");
    }
    else {
        printf("Have a nice journey! :)\n");
    }

    return 0;
}