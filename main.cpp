/*
main.cpp 
загрузка и запуск приложения.
--------------

*/
#include <QApplication>
#include <fstream>
#include <QMessageBox>
//#include "ui_base_win.h"
#include "mainwin.h"
#include <clocale>

int main(int argc, char *argv[]) 
{ 
	//setlocale( LC_ALL,"Russian" );
	QApplication app(argc, argv,true);
	MainWin *mainWin =  new MainWin;
	mainWin->show();
	return app.exec();
}