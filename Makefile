
datasource : datasource/oneworld.pdf datasource/staralliance.pdf datasource/skyteam.exe

datasource/oneworld.pdf :
	mkdir -p datasource
	curl http://www.trvlink.com/download/oneworld/oneworld.pdf > datasource/oneworld.pdf

datasource/staralliance.pdf :
	mkdir -p datasource
	curl http://timetable.staralliance.com/download/star/STAR0001.pdf > datasource/staralliance.pdf

datasource/skyteam.exe :
	mkdir -p datasource
	curl http://www.skyteamtimetable.com/SkyTeamTravelTimetable.exe > datasource/skyteam.exe

skyteam_extract/innoextract-1.4 :
	cd skyteam_extract ; tar -xf innoextract-1.4.tar.gz

skyteam_extract/innoextract-1.4/build/innoextract : skyteam_extract/innoextract-1.4
	mkdir -p skyteam_extract/innoextract-1.4/build
	cd skyteam_extract/innoextract-1.4/build ; cmake ../
	cd skyteam_extract/innoextract-1.4/build ; make

datasource/skyteam/app/serverdll.dll : skyteam_extract/innoextract-1.4/build/innoextract datasource/skyteam.exe
	cd datasource/skyteam/ ; ../../skyteam_extract/innoextract-1.4/build/innoextract ../skyteam.exe
	touch datasource/skyteam/app/serverdll.dll

skyteam_extract/dbextract.exe : skyteam_extract/dbextract.cpp
	cd skyteam_extract ; winegcc -m32 dbextract.cpp -o dbextract

