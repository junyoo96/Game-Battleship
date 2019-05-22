CC= g++
TARGET = Battleship
SOURCES =	BattleShipApp.cpp\
					Pane.cpp\
					InputPane.cpp\
					BattleShipMap.cpp\
					StatPane.cpp\
					GameManager.cpp\
					Position.cpp\
					Ship.cpp\
					Aircraft.cpp\
					Battleship.cpp\
					Cruiser.cpp\
					Destroyer.cpp\
					Player.cpp\
					main.cpp
LDFLAGS = -lncurses

all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -rf *.o $(TARGET)
