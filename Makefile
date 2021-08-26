BIN := text_editor

.PHONY : all debug clean

all:
	cd $(BIN) && make

debug:
	cd $(BIN) && make debug
	
clean:
	cd $(BIN) && make clean
