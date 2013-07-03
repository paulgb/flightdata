 
#include <windows.h> 
#include <stdio.h> 
#include <stdlib.h> 
 
typedef int (__cdecl *FLIGHTSERVERINIT)(const char*); 
typedef int (__cdecl *FLIGHTSERVERCALL)(int, char const*, char*, int); 
typedef int (__cdecl *FLIGHTSERVERTERM)(); 

const int BUFFER_SIZE = 10000;
 
int main( void ) { 
    HINSTANCE serverLib; 
    FLIGHTSERVERINIT FlightServerInit; 
    FLIGHTSERVERCALL FlightServerCall; 
    FLIGHTSERVERTERM FlightServerTerm; 
    BOOL fFreeResult;

    int i;
    char * buffer;
    buffer = (char*) malloc (BUFFER_SIZE);
    char * c;

    printf("Buffer: %p\n", buffer);
 
    serverLib = LoadLibrary(TEXT("ServerDLL.dll")); 
 
    if (serverLib != NULL) { 
        FlightServerInit = (FLIGHTSERVERINIT) GetProcAddress(serverLib, "FlightServerInit"); 
        FlightServerCall = (FLIGHTSERVERCALL) GetProcAddress(serverLib, "FlightServerCall"); 
        FlightServerTerm = (FLIGHTSERVERTERM) GetProcAddress(serverLib, "FlightServerTerm"); 

        printf("FlightServerInit %x\n", (int)FlightServerInit);
        printf("FlightServerCall %x\n", (int)FlightServerCall);
        printf("FlightServerTerm %x\n", (int)FlightServerTerm);
 
        if (NULL != FlightServerInit) {
            i = (FlightServerInit) ("Airline=12&Path=Z:\\Users\\paulbutler\\Projects\\flightdata\\innoextract-1.4\\build\\app\\&Language=en");
            printf("Result of FlightServerInit %x\n", i);

            i = (FlightServerCall) (NULL, "http://startup/?Service=Itinerary&Action=Create&Format=XML&Device=12&ITID=zwanda", buffer, BUFFER_SIZE);
            printf("Result of FlightServerCall %i\n", i);
            printf("%s", buffer);

            i = (FlightServerTerm) ();
            printf("Result of FlightServerTerm %i\n", i);
        }
 
        fFreeResult = FreeLibrary(serverLib); 
    } else {
        printf("Couldn't load ServerDLL.dll\n");
    }

    free(buffer);

    return 0;

}

