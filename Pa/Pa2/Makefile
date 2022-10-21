CPPFLAGS = -std=c++11
CPPFLAGS_L = -std=c++11 -fsanitize=address,leak,undefined
ZIPFILES = grass.cpp animal.cpp sheep.cpp wolf.cpp
SRCS = main.cpp animal.cpp board.cpp entity.cpp helper.cpp grass.cpp sheep.cpp wolf.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: PA2.exe PA2_leak.exe submit.zip

PA2.exe: $(OBJS)
	g++ -o $@ $(CPPFLAGS) $^

PA2_leak.exe: $(OBJS)
	g++ -o $@ $(CPPFLAGS_L) $^

cleanZip:
	rm  -f AAA_submit.zip

submit.zip: cleanZip
	zip -r AAA_submit.zip $(ZIPFILES)

%.o: %.cpp
	g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f *.o *.exe *.d AAA_submit.zip
# On Windows, use: del *.o *.exe *.d
# On Linux or MacOS, use: rm -f *.o *.exe *.d

.PRECIOUS: $(OBJS)