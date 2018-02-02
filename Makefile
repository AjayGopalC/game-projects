#makefile

#C++ Group Project - AUTUMN - 2017

#Group 6
## Members:
## Ajay Gopal Changarath
## Anirudh Chandrachoodan
## John Philip Parambil
## Kishore Sukumaran
## Stanislaw Adamczewski

#this make file builds the executable file name gameexe from the fileMain.cpp

CC= g++

CPPFLAGS= -ggdb -Wall

TARGET= CardGame

all:	$(TARGET)

$(TARGET):	$(TARGET).cpp
	$(CC) $(CPPFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)
