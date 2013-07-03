 
#include <windows.h> 
#include <stdio.h> 
#include <stdlib.h> 

typedef int (__cdecl *FLIGHTSERVERINIT)(const char*); 
typedef int (__cdecl *FLIGHTSERVERCALL)(int, char const*, char*, int); 
typedef int (__cdecl *FLIGHTSERVERTERM)(); 

const int BUFFER_SIZE = 10000;
 
int main( int argc, char **argv ) { 
    if (argc != 3) {
        printf("Usage: dbextract.exe <Path to ServerDLL> <startup string>\n");
        return -1;
    }

    char *dll_path = argv[1];
    char *startup_string = argv[2];

    printf("DLL Path: %s\n", dll_path);
    printf("Startup string: %s\n", startup_string);
    
    HINSTANCE serverLib; 
    FLIGHTSERVERINIT FlightServerInit; 
    FLIGHTSERVERCALL FlightServerCall; 
    FLIGHTSERVERTERM FlightServerTerm; 
    BOOL fFreeResult;

    int i;
    char * buffer;
    buffer = (char*) malloc (BUFFER_SIZE);
    char * c;

    serverLib = LoadLibrary(dll_path); 
 
    if (serverLib == NULL) { 
        printf("fial\n");
        return -1;
    }

    printf("serverLib %x\n", (int)serverLib);

    FlightServerInit = (FLIGHTSERVERINIT) GetProcAddress(serverLib, "FlightServerInit"); 
    FlightServerCall = (FLIGHTSERVERCALL) GetProcAddress(serverLib, "FlightServerCall"); 
    FlightServerTerm = (FLIGHTSERVERTERM) GetProcAddress(serverLib, "FlightServerTerm"); 

    printf("FlightServerInit %x\n", (int)FlightServerInit);
    printf("FlightServerCall %x\n", (int)FlightServerCall);
    printf("FlightServerTerm %x\n", (int)FlightServerTerm);

    if (NULL != FlightServerInit) {
        //i = (FlightServerInit) ("Airline=12&Path=Z:\\Users\\paulbutler\\Projects\\flightdata\\innoextract-1.4\\build\\app\\&Language=en");
        i = (FlightServerInit) (startup_string);
        printf("Result of FlightServerInit %x\n", i);

        char x [300];
        fgets(x, 300, stdin);
        //i = (FlightServerCall) (NULL, "http://startup/?Service=Itinerary&Action=Create&Format=XML&Device=12&ITID=zwanda", buffer, BUFFER_SIZE);
        i = (FlightServerCall) (NULL, x, buffer, BUFFER_SIZE);
        printf("Result of FlightServerCall %i\n", i);
        printf("%s", buffer);

        i = (FlightServerTerm) ();
        printf("Result of FlightServerTerm %i\n", i);
    }

    fFreeResult = FreeLibrary(serverLib); 

    free(buffer);

    return 0;

}

