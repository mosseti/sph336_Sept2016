# Makefile
# Created on: Oct 28, 2016
#      Author: karibe

GTKWAVE := $(shell which gtkwave)


all: decoder

decoder:prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.1/include -O0 -g3 -Wall -c decoder2_by4.cc
	$(CXX) -L/usr/local/systemc-2.3.1/lib-linux64 -o decoder decoder2_by4.o -lsystemc
	./decoder
	gtkwave -c 4 timing_diagram.vcd

prerequisites: 
ifneq "$(GTKWAVE)" "/usr/bin/gtkwave"
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm *.out *.o *.vcd

.PHONY: decoder
