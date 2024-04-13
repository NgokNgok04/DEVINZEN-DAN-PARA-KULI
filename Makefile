CXX = g++
SRC = src
IMP = Implementation

GODriver: Bangunan.o GameManager.o GameObject.o helper.o Hewan.o ParserHewan.o ParserMisc.o ParserProduk.o ParserResep.o ParserTanaman.o Product.o Tanaman.o GameObjectDriver.o
	g++ Bangunan.o GameManager.o GameObject.o helper.o Hewan.o ParserHewan.o ParserMisc.o ParserProduk.o ParserResep.o ParserTanaman.o Product.o Tanaman.o GameObjectDriver.o -o GODriver

ParserDriver:Bangunan.o GameManager.o GameObject.o helper.o Hewan.o ParserHewan.o ParserMisc.o ParserProduk.o ParserResep.o ParserTanaman.o Product.o Tanaman.o parserdriver.o
	g++ Bangunan.o GameManager.o GameObject.o helper.o Hewan.o ParserHewan.o ParserMisc.o ParserProduk.o ParserResep.o ParserTanaman.o Product.o Tanaman.o parserdriver.o -o ParserDriver
Bangunan.o: $(SRC)/$(IMP)/Bangunan.cpp
	g++ -c $(SRC)/$(IMP)/Bangunan.cpp

GameManager.o: $(SRC)/$(IMP)/GameManager.cpp
	g++ -c $(SRC)/$(IMP)/GameManager.cpp

GameObject.o: $(SRC)/$(IMP)/GameObject.cpp
	g++ -c $(SRC)/$(IMP)/GameObject.cpp

GameObjectDriver.o: $(SRC)/GameObjectDriver.cpp
	g++ -c $(SRC)/GameObjectDriver.cpp

helper.o: $(SRC)/$(IMP)/helper.cpp
	g++ -c $(SRC)/$(IMP)/helper.cpp

Hewan.o: $(SRC)/$(IMP)/Hewan.cpp
	g++ -c $(SRC)/$(IMP)/Hewan.cpp

ParserHewan.o: $(SRC)/$(IMP)/ParserHewan.cpp
	g++ -c $(SRC)/$(IMP)/ParserHewan.cpp

ParserMisc.o: $(SRC)/$(IMP)/ParserMisc.cpp
	g++ -c $(SRC)/$(IMP)/ParserMisc.cpp

ParserProduk.o: $(SRC)/$(IMP)/ParserProduk.cpp
	g++ -c $(SRC)/$(IMP)/ParserProduk.cpp

ParserResep.o: $(SRC)/$(IMP)/ParserResep.cpp
	g++ -c $(SRC)/$(IMP)/ParserResep.cpp

ParserTanaman.o: $(SRC)/$(IMP)/ParserTanaman.cpp
	g++ -c $(SRC)/$(IMP)/ParserTanaman.cpp

Product.o: $(SRC)/$(IMP)/Product.cpp
	g++ -c $(SRC)/$(IMP)/Product.cpp

Tanaman.o: $(SRC)/$(IMP)/Tanaman.cpp
	g++ -c $(SRC)/$(IMP)/Tanaman.cpp

parserdriver.o: $(SRC)/parserdriver.cpp
	g++ -c $(SRC)/parserdriver.cpp
