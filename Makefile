CC = g++
CFLAGS = -Wall -g
.RECIPEPREFIX = >

program: Sensor.o Moisture.o Temp.o Light.o CamTherm.o CamRGB.o AirQ.o User.o Admin.o DBUser.o Dashboard.o main.o 
>$(CC) $(CFLAGS) -o program Sensor.o Moisture.o Temp.o Light.o CamTherm.o CamRGB.o AirQ.o User.o Admin.o DBUser.o Dashboard.o main.o

Sensor.o: include/Sensor.h
>touch Sensor.o

Moisture.o: Moisture.cpp include/Moisture.h include/Sensor.h
>$(CC) $(CFLAGS) -c Moisture.cpp

Temp.o: Temp.cpp include/Temp.h include/Sensor.h
>$(CC) $(CFLAGS) -c Temp.cpp

Light.o: Light.cpp include/Light.h include/Sensor.h
>$(CC) $(CFLAGS) -c Light.cpp

CamTherm.o: CamTherm.cpp include/CamTherm.h include/Sensor.h
>$(CC) $(CFLAGS) -c CamTherm.cpp

CamRGB.o: CamRGB.cpp include/CamRGB.h include/Sensor.h
>$(CC) $(CFLAGS) -c CamRGB.cpp

AirQ.o: AirQ.cpp include/AirQ.h include/Sensor.h
>$(CC) $(CFLAGS) -c AirQ.cpp

User.o: User.cpp include/User.h
>$(CC) $(CFLAGS) -c User.cpp

Admin.o: Admin.cpp include/Admin.h include/User.h
>$(CC) $(CFLAGS) -c Admin.cpp

DBUser.o: DBUser.cpp include/DBUser.h include/User.h
>$(CC) $(CFLAGS) -c DBUser.cpp

Dashboard.o: Dashboard.cpp include/Dashboard.h include/Sensor.h include/Moisture.h include/Temp.h include/Light.h include/CamTherm.h include/CamRGB.h include/AirQ.h include/DBUser.h
>$(CC) $(CFLAGS) -c Dashboard.cpp

main.o: main.cpp include/Dashboard.h
>$(CC) $(CFLAGS) -c main.cpp

clean:
>rm -f *.o program