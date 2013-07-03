 
#include <windows.h> 
#include <stdio.h> 
#include <stdlib.h> 

typedef int (__cdecl *FLIGHTSERVERINIT)(const char*); 
typedef int (__cdecl *FLIGHTSERVERCALL)(int, char const*, char*, int); 
typedef int (__cdecl *FLIGHTSERVERTERM)(); 

const int BUFFER_SIZE = 10000;

FLIGHTSERVERINIT FlightServerInit; 
FLIGHTSERVERCALL FlightServerCall; 
FLIGHTSERVERTERM FlightServerTerm; 

char * buffer;

extern "C" {
    int init(char *dll_path, char *startup_string) {
        HINSTANCE serverLib; 
        printf("DLL Path: %s\n", dll_path);
        printf("Startup string: %s\n", startup_string);

        //buffer = (char*) malloc (BUFFER_SIZE);
        printf("foo bar\n");
        printf("%p\n", buffer);

        //serverLib = LoadLibrary(dll_path); 
        serverLib = LoadLibrary(TEXT("serverdll.dll")); 
        /*
        printf("here1\n");

        if (serverLib == NULL) { 
            printf("fial\n");
            return -1;
        }

        FlightServerInit = (FLIGHTSERVERINIT) GetProcAddress(serverLib, "FlightServerInit"); 
        FlightServerCall = (FLIGHTSERVERCALL) GetProcAddress(serverLib, "FlightServerCall"); 
        FlightServerTerm = (FLIGHTSERVERTERM) GetProcAddress(serverLib, "FlightServerTerm"); 

        printf("FlightServerInit %x\n", (int)FlightServerInit);
        printf("FlightServerCall %x\n", (int)FlightServerCall);
        printf("FlightServerTerm %x\n", (int)FlightServerTerm);

        if (NULL != FlightServerInit) {
            //i = (FlightServerInit) ("Airline=12&Path=Z:\\Users\\paulbutler\\Projects\\flightdata\\innoextract-1.4\\build\\app\\&Language=en");
            int i = (FlightServerInit) (startup_string);
            printf("Result of FlightServerInit %x\n", i);
        }
        */
        return 1;
    }

    int flightServerCall(char const*, char*, int) {
        return 10;
    }

    int main (int argc, char **argv) {

    }
}


//i = (FlightServerCall) (NULL, "http://startup/?Service=Itinerary&Action=Create&Format=XML&Device=12&ITID=zwanda", buffer, BUFFER_SIZE);

