#include <pthread.h>
#include <stdio.h>

int i = 0;

// Note the return type: void* (pointer)
void* incrementingThreadFunction(){
    int j;
    for(j=0; j<1000000;j++){
        i++;
    }
    return NULL;
}

void* decrementingThreadFunction(){
     int j;
    for(j=0; j<1000000;j++){
        i--;
    }
    return NULL;
}


int main(){
    // TODO: declare incrementingThread and decrementingThread (hint: google pthread_create)
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
