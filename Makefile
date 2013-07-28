
all : extracted

# Data Acquisition

datasource : datasource/oneworld.pdf datasource/staralliance.pdf datasource/skyteam.exe

# Fetch Data for each alliance over HTTP

datasource/oneworld.pdf :
	mkdir -p datasource
	curl http://www.trvlink.com/download/oneworld/oneworld.pdf > datasource/oneworld.pdf

datasource/staralliance.pdf :
	mkdir -p datasource
	curl http://timetable.staralliance.com/download/star/STAR0001.pdf > datasource/staralliance.pdf

datasource/skyteam.exe :
	mkdir -p datasource
	curl http://www.skyteamtimetable.com/SkyTeamTravelTimetable.exe > datasource/skyteam.exe

# Skyteam Data Extraction
# Skyteam's pipeline is the most complicated: their timetable is available only
# as a Windows executable with a proprietary data format. See README.md for details on
# the data extraction process.

skyteam_extract/innoextract-1.4/VERSION :
	cd skyteam_extract ; tar -xf innoextract-1.4.tar.gz

skyteam_extract/innoextract-1.4/build/innoextract : skyteam_extract/innoextract-1.4/VERSION
	mkdir -p skyteam_extract/innoextract-1.4/build
	cd skyteam_extract/innoextract-1.4/build ; cmake ../
	cd skyteam_extract/innoextract-1.4/build ; make

datasource/skyteam/app/serverdll.dll : skyteam_extract/innoextract-1.4/build/innoextract datasource/skyteam.exe
	cd datasource/skyteam/ ; ../../skyteam_extract/innoextract-1.4/build/innoextract ../skyteam.exe
	touch datasource/skyteam/app/serverdll.dll

datasource/skyteam/app/Devices/12/display-csv : datasource/skyteam/app/serverdll.dll
	cp skyteam_extract/display-csv datasource/skyteam/app/Devices/12/display-csv

skyteam_extract/dbextract.exe : skyteam_extract/dbextract.cpp skyteam_extract/cities.h
	cd skyteam_extract ; winegcc -m32 dbextract.cpp -o dbextract

# PDF Data Extraction

extracted : extracted/staralliance.csv extracted/oneworld.csv

extracted/staralliance.csv : datasource/staralliance.pdf pdf_parse/parse.py pdf_parse/staralliance.py
	mkdir -p extracted
	python pdf_parse/staralliance.py datasource/staralliance.pdf extracted/staralliance.csv

extracted/oneworld.csv : datasource/oneworld.pdf pdf_parse/parse.py pdf_parse/oneworld.py
	mkdir -p extracted
	python pdf_parse/oneworld.py datasource/oneworld.pdf extracted/oneworld.csv


