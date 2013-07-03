
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

