#include <stdio.h>
     
    #define min(A,B) ((A)>(B)?(B):(A))
    #define max(A,B) ((A)>(B)?(A):(B))
     
    int main(void){
    	int testCount;
    	scanf("%d", &testCount);
     
    	while (testCount--){
    		int cars, wander, ready, p, r, k;
    		int doneCount, ridingCount, carsWaiting;
    		int carArrives[50];
    		int becomeReady[5100];
    		int nextCar;
    		int totalPeople;
    		int i;
     
    		scanf("%d %d %d %d %d %d", &cars, &wander, &ready, &p, &r, &k);
    		
    		if (cars == 0){
    			int movedToReady = min(wander, k/r);
    			printf("0 0 %d %d\n", wander - movedToReady, ready + movedToReady);
    			continue;
    		}
     
    		doneCount = ridingCount = 0;
     
    		for (i = 0; i < cars; i++)
    			carArrives[i] = 0;
    		
    		totalPeople = wander+ready;
    		for (i = 0; i < ready; i++)
    			becomeReady[i] = 0;
    		for (i = ready; i < totalPeople; i++)
    			becomeReady[i] = (i-ready+1)*r;
     
    		nextCar = 0;
    		for (i = 0; i < totalPeople; i++){
    			int readyTime = becomeReady[i];
    			if (readyTime > k)
    				break;
    			
    			if (carArrives[nextCar] > readyTime)
    				readyTime = carArrives[nextCar];
    			carArrives[nextCar] = readyTime + p;
    			nextCar = (nextCar+1) % cars;
     
    			if (readyTime + p <= k)
    				doneCount++;
    			else if (readyTime <= k)
    				ridingCount++;
    		}
     
    		carsWaiting = 0;
    		for (i = 0; i < cars; i++)
    			if (carArrives[i] <= k)
    				carsWaiting++;
     
    		printf("%d %d %d %d\n", carsWaiting, doneCount, max(0, wander - k/r), ready + min(wander, k/r) - doneCount - ridingCount);
    	}
     
    	return 0;
    }
