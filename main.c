#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STOPS 4
#define MAX_BUSES 1

void print_menu();
void print_time();
float TaxiFare(float);
float BusFare515(int);
float BusStation515(int);
float BusFare547(int);
float BusStation547(int);
float BusFare556(int);
float BusStation556(int);
float BusFare124(int);
float BusStation124(int);
float PetroPrice(float, float, float);

//choice
int main(){
  int choice, press, i=0;
  float distance1, distance2, fare, price, liters, total;
  float TotalBusFare;
  int YourLocation, bus_line, station; 
  int line515, line556, line547, line124;
  char Line515[800], Line556[800], Line547[800], Line124[800];

  FILE *station124;
  station124 = fopen("124.DAT","r");
  if (station124 == NULL) {
      printf("Error opening file 124.DAT\n");
      return 1;
  }
  FILE *station515;
  station515 = fopen("515.DAT","r");
  if (station515 == NULL) {
      printf("Error opening file 124.DAT\n");
      return 1;
  }
  FILE *station547;
  station547 = fopen("547.DAT","r");
  if (station547 == NULL) {
      printf("Error opening file 124.DAT\n");
      return 1;
  }
  FILE *station556;
  station556 = fopen("556.DAT","r");
  if (station556 == NULL) {
      printf("Error opening file 124.DAT\n");
      return 1;
  }
  
  
  do{
    print_menu();
    scanf("%d", &choice);
    
    switch(choice){
      case 1:
        fare = TaxiFare(distance1); 
        printf("\n------------------------------------\n");
        printf("**Taxi Fare Summary**\n");
        //printf("Distance: %.2f kilometers\n",distance1);
        printf("Total Fare: %.2f baht\n",fare);
        break;

      
    case 2:
      do {
        printf("\n============== Welcome to Bus (AC) ==============\n");
        print_time();
        printf("----- Your destination is Mahidol University -----\n");
        printf("Enter your bus line: ");
        scanf("%d", &bus_line);
      
  if(bus_line == 515){
    printf("Station lists\n"); 
      while (fscanf(station515, "%d %800s", &line515, Line515) == 2) {
      printf("%d %s\n", line515, Line515);
    } 
    fclose(station515);
    
      printf("Enter your location number: ");
      scanf("%d", &YourLocation);
    TotalBusFare = BusFare515(YourLocation);
    station = BusStation515(YourLocation);

    printf("----------------------------------------\n");
    printf("Total Bus Fare is %.2f baht\n", TotalBusFare);

        if(station == 1) printf("There is 1 station left\n");
        else printf("There are %d stations left\n", station);
    printf("----------------------------------------\n");
        break;
      
      }
      
  else if (bus_line == 547){
    printf("Station lists\n"); 
    while (fscanf(station547, "%d %1000s", &line547, Line547) == 2) {
    printf("%d %s\n", line547, Line547);
    }
    fclose(station547);
    
      printf("Enter your location number: ");
      scanf("%d", &YourLocation);
    TotalBusFare = BusFare547(YourLocation);
    station = BusStation547(YourLocation);

    printf("----------------------------------------\n");
    printf("Total Bus Fare is %.2f baht\n", TotalBusFare);

        if(station == 1) printf("There is 1 station left\n");
        else printf("There are %d stations left\n", station);
    printf("----------------------------------------\n");
        break;
      }

  else if (bus_line == 556){
    printf("Station lists\n"); 
        while (fscanf(station556, "%d %1000s", &line556, Line556) == 2) {
          printf("%d %s\n", line556, Line556);
    }
    fclose(station556);
    
      printf("Enter your location number: ");
      scanf("%d", &YourLocation);
    TotalBusFare = BusFare556(YourLocation);
    station = BusStation556(YourLocation);

    printf("----------------------------------------\n");
    printf("Total Bus Fare is %.2f baht\n", TotalBusFare);

        if(station == 1) printf("There is 1 station left\n");
        else printf("There are %d stations left\n", station);
    printf("----------------------------------------\n");
        break;
      }

  else if (bus_line == 124){
    printf("Station lists\n"); 
      while (fscanf(station124, "%d %800s", &line124, Line124) == 2) {
    printf("%d %s\n", line124, Line124);
    }
    fclose(station124);
    
      printf("Enter your location number: ");
      scanf("%d", &YourLocation);
      TotalBusFare = BusFare124(YourLocation);
      station = BusStation124(YourLocation);

      printf("----------------------------------------\n");
      printf("Total Bus Fare is %.2f baht\n", TotalBusFare);

          if(station == 1) printf("There is 1 station left\n");
          else printf("There are %d stations left\n", station);
      printf("----------------------------------------\n");
          break;
      }
      
  else {
        printf("Invalid bus line. Please try again.\n");
        i++;
      }
        
      } while(i!=0);
        
     break;

      
    case 3:
      printf("Enter distance in km: ");
      scanf("%f", &distance2);
      printf("Petro price per liter: ");
      scanf(" %f", &price);
      printf("Enter fuel consumption(liters per km): ");
      scanf("%f", &liters);

      total = PetroPrice(distance2, price, liters);
      printf("\nTotal price is %.2f baht\n",total);
        break;
      
    default: printf("Invalid choice\n");
    //break;
  }
    puts("\nDo you want to continue?");
    printf("Press '1' to continue or '2' to exit : ");
    scanf("%d", &press);
    
  } while(press==1);
  return 0;
}  

void print_menu(){
printf("-------------------------------------------------\n");
puts("Welcome to Trasportation Calculator Service");
puts("Choice 1 : Taxi Fare Calculator");
puts("Choice 2 : Bus Fare and Bus Station Calculator");
puts("Choice 3 : Petroleum Price Calculator");
printf("-------------------------------------------------\n");
printf("Select your choice : ");
}

void print_time(){
    char busTimes515[MAX_STOPS][MAX_BUSES][13];
    char busTimes547[MAX_STOPS][MAX_BUSES][13];
    char busTimes556[MAX_STOPS][MAX_BUSES][13];
    char busTimes124[MAX_STOPS][MAX_BUSES][13];

    snprintf(busTimes515[0][0], sizeof(busTimes515[0][0]), "05:00-23:00");
    snprintf(busTimes515[1][0], sizeof(busTimes515[1][0]), "05:00-23:00");
    snprintf(busTimes515[2][0], sizeof(busTimes515[2][0]), "05:00-23:00");

    snprintf(busTimes547[0][0], sizeof(busTimes547[0][0]), "06:00-21:30");
    snprintf(busTimes547[1][0], sizeof(busTimes547[1][0]), "06:00-21:30");
    snprintf(busTimes547[2][0], sizeof(busTimes547[2][0]), "06:00-21:30");

    snprintf(busTimes556[0][0], sizeof(busTimes556[0][0]), "05:00-18:30");
    snprintf(busTimes556[1][0], sizeof(busTimes556[1][0]), "06:00-18:30");
    snprintf(busTimes556[2][0], sizeof(busTimes556[2][0]), "06:00-18:30");

    snprintf(busTimes124[0][0], sizeof(busTimes124[0][0]), "06:00-20:10");
    snprintf(busTimes124[1][0], sizeof(busTimes124[1][0]), "06:20-20:10");
    snprintf(busTimes124[2][0], sizeof(busTimes124[2][0]), "07:30-20:10");

    printf("%8s %18s %11s %14s\n", "Bus Line", "Mon-Fri", "Sat", "Sun");

    printf("Bus Line 515 ");
    for (int stop = 0; stop < MAX_STOPS; stop++) {
        printf("%15s", busTimes515[stop][0]);
    }
    printf("\n");

    printf("Bus Line 547 ");
    for (int stop = 0; stop < MAX_STOPS; stop++) {
        printf("%15s", busTimes547[stop][0]);
    }
    printf("\n");

    printf("Bus Line 556 ");
    for (int stop = 0; stop < MAX_STOPS; stop++) {
        printf("%15s", busTimes556[stop][0]);
    }
    printf("\n");

    printf("Bus Line 124 ");
    for (int stop = 0; stop < MAX_STOPS; stop++) {
        printf("%15s", busTimes124[stop][0]);
    }
    printf("\n");
}

float TaxiFare(float distance1){
  float fare;
  int InValidDistance = 0;
  printf("\n");
  printf("-------- Taxi Fare Calculator --------\n");
  printf("       !Thailand only Edition!         \n");
  printf("\n");
  printf("\nEnter the distance in km: ");
      scanf("%f", &distance1);

  for (; !InValidDistance;) {
      if (distance1 <= 0) {
          printf("Error: Invalid distance. Distance must be greater than 0 na ja.\n\n");
      } else {
          InValidDistance = 1;
      }
  }
  if (distance1 <= 1) {
      fare =35.00;
  } else if (distance1 <= 10) {
      fare =35.00+(distance1-1) * 6.50;
  } else if (distance1 <= 20) {
      fare =35.00+(9*6.50)+(distance1-10) * 7.00;
  } else if (distance1 <= 40) {
      fare =35.00+(9*6.50)+(10*7.00)+(distance1 - 20) * 8.00;
  } else if (distance1 <= 60) {
      fare =35.00+(9*6.50)+(10*7.00)+(20*8.00)+(distance1-40) * 8.50;
  } else if (distance1 <= 80) {
      fare =35.00+(9*6.50)+(10*7.00)+(20*8.00)+(20*8.50)+(distance1-60) * 9.00;
  } else {
      fare =35.00+(9*6.50)+(10*7.00)+(20*8.00)+(20*8.50)+(20*9.00)+(distance1-80) *10.50;
  }

  return fare;
}



//bus fare n station
float BusFare515(int Yourlocation){
  int remainingStations;
  remainingStations = 40-Yourlocation;
  float cost;

  if (remainingStations >= 1 && remainingStations <= 10) cost = 15;
   else if (remainingStations >= 11 && remainingStations <= 15) cost = 20;
    else cost = 25;

  return cost;
}



float BusStation515(int Yourlocation){
  int RemainingStations = 40-Yourlocation;
  return RemainingStations;
}



float BusFare547(int Yourlocation){
  int remainingStations;
  remainingStations = 93-Yourlocation;
  float cost;

  if (remainingStations >= 1 && remainingStations <= 10) cost = 14;
   else if (remainingStations >= 11 && remainingStations <= 15) cost = 20;
    else cost = 25;

  return cost;
}


float BusStation547(int Yourlocation){
  int RemainingStations = 93-Yourlocation;
  return RemainingStations;
}


float BusFare556(int Yourlocation){
  int remainingStations;
  remainingStations = 43-Yourlocation;
  float cost;

  if (remainingStations >= 1 && remainingStations <= 10) cost = 15;
   else if (remainingStations >= 11 && remainingStations <= 15) cost = 20;
    else cost = 22;

  return cost;
}


float BusStation556(int Yourlocation){
  int RemainingStations = 43-Yourlocation;
  return RemainingStations;
}


float BusFare124(int Yourlocation){
  int remainingStations;
  remainingStations = 41-Yourlocation;
  float cost;
  
  if (remainingStations >= 1 && remainingStations <= 10) cost = 15;
   else if (remainingStations >= 11 && remainingStations <= 15) cost = 20;
    else cost = 25;
  
  return cost;
}


float BusStation124(int Yourlocation){
  int RemainingStations = 41-Yourlocation;
  return RemainingStations;
}


//oil price
float PetroPrice(float distance2, float price, float liters){
  float total;
  total= (distance2/liters)*price;
  return total;
}
