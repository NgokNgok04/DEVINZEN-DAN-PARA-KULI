CXX = g++
SRC = src
IMP = Implementation

final: Bangunan.o matrixarea.o GameManager.o GameObject.o helper.o Hewan.o ParserHewan.o ParserMisc.o ParserProduk.o ParserResep.o ParserTanaman.o Product.o Tanaman.o  pemain.o petani.o peternak.o walikota.o Toko.o pcolor.o main.o
	g++ Bangunan.o matrixarea.o GameManager.o GameObject.o helper.o Hewan.o ParserHewan.o ParserMisc.o ParserProduk.o ParserResep.o ParserTanaman.o Product.o Tanaman.o pemain.o petani.o peternak.o walikota.o Toko.o pcolor.o main.o -o main
GODriver: Bangunan.o GameManager.o GameObject.o helper.o Hewan.o ParserHewan.o ParserMisc.o ParserProduk.o ParserResep.o ParserTanaman.o Product.o Tanaman.o GameObjectDriver.o
	g++ Bangunan.o GameManager.o GameObject.o helper.o Hewan.o ParserHewan.o ParserMisc.o ParserProduk.o ParserResep.o ParserTanaman.o Product.o Tanaman.o GameObjectDriver.o -o GODriver
	rm *.o
ParserDriver:Bangunan.o GameManager.o GameObject.o helper.o Hewan.o ParserHewan.o ParserMisc.o ParserProduk.o ParserResep.o ParserTanaman.o Product.o Tanaman.o parserdriver.o
	g++ Bangunan.o GameManager.o GameObject.o helper.o Hewan.o ParserHewan.o ParserMisc.o ParserProduk.o ParserResep.o ParserTanaman.o Product.o Tanaman.o parserdriver.o -o ParserDriver
	rm *.o
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

matrixarea.o: $(SRC)/$(IMP)/matrixarea.cpp
	g++ -c $(SRC)/$(IMP)/matrixarea.cpp

pemain.o: $(SRC)/$(IMP)/pemain.cpp
	g++ -c $(SRC)/$(IMP)/pemain.cpp

petani.o: $(SRC)/$(IMP)/petani.cpp
	g++ -c $(SRC)/$(IMP)/petani.cpp

peternak.o: $(SRC)/$(IMP)/peternak.cpp
	g++ -c $(SRC)/$(IMP)/peternak.cpp

walikota.o: $(SRC)/$(IMP)/walikota.cpp
	g++ -c $(SRC)/$(IMP)/walikota.cpp

pcolor.o: $(SRC)/$(IMP)/pcolor.cpp
	g++ -c $(SRC)/$(IMP)/pcolor.cpp

Toko.o: $(SRC)/$(IMP)/Toko.cpp
	g++ -c $(SRC)/$(IMP)/Toko.cpp
parserdriver.o: $(SRC)/parserdriver.cpp
	g++ -c $(SRC)/parserdriver.cpp

main.o: $(SRC)/main.cpp
	g++ -c $(SRC)/main.cpp

