OBJECTS=threadif.o \
		asynctcpserver.o \
		asynctcpclient.o \
		serverprocess.o \
		timer.o \
		handled.o\
		handlemanager.o\
		baseexception.o \
		timerqueue.o


CC=g++
AR=ar
TARGETS=libet.so libet.a test

CPPFLAGS=-g -I./include

LDFLAGS=-L./lib -lgtest_main -lpthread -llog4cplus -ltinyxml -let -ldl -Wl,-rpath ./lib


all:$(TARGETS)

libet.so:$(OBJECTS)
	$(CC) -shared -fPIC -o $@ $^

libet.a:$(OBJECTS)
	$(AR) rv $@ $^

$(OBJECTS):%.o:%.cpp %.h
	$(CC) -c $(CPPFLAGS) $< -o $@ 

test:test.cc libet.so
	$(CC) $(CPPFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(OBJECTS) core $(TARGETS) $(MODULES)
