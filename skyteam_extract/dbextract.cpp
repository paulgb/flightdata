 
#include <windows.h> 
#include <stdio.h> 
#include <stdlib.h> 

#include "cities.h"

typedef int (__cdecl *FLIGHTSERVERINIT)(const char*); 
typedef int (__cdecl *FLIGHTSERVERCALL)(int, char const*, char*, int); 
typedef int (__cdecl *FLIGHTSERVERTERM)(); 

const int BUFFER_SIZE = 100000;
const int COMMAND_SIZE = 1000;
 
int main( int argc, char **argv ) { 
    int num_cities = sizeof(cities) / sizeof(cities[0]);

    const char *dll_path = "serverdll.dll";
    const char *startup_string = "";
    char *command = (char*) malloc (COMMAND_SIZE);

    printf("DLL Path: %s\n", dll_path);
    printf("Startup string: %s\n", startup_string);
    
    HINSTANCE serverLib; 
    FLIGHTSERVERINIT FlightServerInit; 
    FLIGHTSERVERCALL FlightServerCall; 
    FLIGHTSERVERTERM FlightServerTerm; 
    BOOL fFreeResult;

    int r;
    char * buffer;
    buffer = (char*) malloc (BUFFER_SIZE);

    serverLib = LoadLibrary(dll_path); 
 
    if (serverLib == NULL) { 
        printf("fail\n");
        return -1;
    }

    printf("serverLib %x\n", (int)serverLib);

    FlightServerInit = (FLIGHTSERVERINIT) GetProcAddress(serverLib, "FlightServerInit"); 
    FlightServerCall = (FLIGHTSERVERCALL) GetProcAddress(serverLib, "FlightServerCall"); 
    FlightServerTerm = (FLIGHTSERVERTERM) GetProcAddress(serverLib, "FlightServerTerm"); 

    printf("FlightServerInit %x\n", (int)FlightServerInit);
    printf("FlightServerCall %x\n", (int)FlightServerCall);
    printf("FlightServerTerm %x\n", (int)FlightServerTerm);

    if (NULL == FlightServerInit) {
        printf("fail 2\n");
        return -1;
    }

    r = (FlightServerInit) (startup_string);
    printf("Result of FlightServerInit %x\n", r);

    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_cities; j++) {

            snprintf(command, COMMAND_SIZE, "http://local/info.html/?Compete=6&Date1=7/3/13&Language=en&StartDate=&EndDate=&From=%s&To=%s&Month=Jul&DayOfMonth=3&Hops=DIRECT&Compression=OPTIMAL&Results=25&Format=csv", cities[i], cities[j]);
            r = (FlightServerCall) (NULL, command, buffer, BUFFER_SIZE);
            if (r != 652) {
                printf("%s\n", buffer);
            }
        }
    }

    r = (FlightServerTerm) ();
    printf("Result of FlightServerTerm %i\n", r);


    fFreeResult = FreeLibrary(serverLib); 
    free(buffer);

    return 0;

}

