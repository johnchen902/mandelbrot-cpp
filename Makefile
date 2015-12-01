# Common variables
CC = g++
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d
CPPFLAGS = -c -std=c++11 -Wall -Wextra -Wshadow -O3
LDFLAGS = -pthread
SOURCES = $(wildcard *.cpp)
DEPENDS = $(SOURCES:.cpp=.d)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = mandelbrot

# Arguments for GTKMM
LDFLAGS += $(shell pkg-config --libs gtkmm-3.0)
SOURCES_GUI = $(wildcard gui*.cpp)
$(SOURCES_GUI:.cpp=.o) : EXTRACPPFLAGS = $(shell pkg-config --cflags gtkmm-3.0 | sed s/-I/-isystem/g)



.PHONY: all clean

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp %.d
	$(CC) $(CPPFLAGS) $(EXTRACPPFLAGS) $(DEPFLAGS) $< -o $@

%.d : ;

clean :
	$(RM) $(EXECUTABLE) $(wildcard *.o) $(wildcard *.d)

ifneq ($(MAKECMDGOALS),clean)
-include $(patsubst %,%.d,$(basename $(SOURCES)))
endif

