TARGET = main.out
FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# XXX: Don't forget backslash at the end of any line except the last one
HDRS = \
	    project/include

SRCS = \
	project/src/allomant.cpp \
	project/src/allomantic_power.cpp \
	project/src/being.cpp \
	project/src/cell.cpp \
	project/src/field.cpp \
	project/src/game.cpp \
	project/src/item.cpp \
	project/src/main.cpp \
	project/src/menu.cpp \
	project/src/metal.cpp \
	project/src/mistborn.cpp \
	project/src/misting.cpp \
	project/src/object.cpp \
	project/src/page.cpp \
	project/src/player.cpp \
	project/src/soldier.cpp \
	project/src/store.cpp \
	project/src/tab.cpp \
	project/src/ui.cpp \
	project/src/button.cpp


.PHONY: all cleanm

all: $(SRCS)
	$(CXX) -std=gnu++17 -Wall -Wextra -w $(addprefix -I,$(HDRS)) -o $(TARGET) $(CFLAGS) $(SRCS) $(FLAGS)	
 
clean:
	rm -rf $(TARGET)
