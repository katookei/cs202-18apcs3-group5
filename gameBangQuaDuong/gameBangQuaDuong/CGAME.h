#pragma once
#include"Header.h"
#include"CCAR.h"
#include"CTRUCK.h"
#include"CBIRD.h"
#include"CDINAUSOR.h"
#include"CPEOPLE.h"

#define TOP 4
#define BOTTOM 28
#define LEFT 2
#define RIGHT 116

class CGAME
{
	int lvl = 1;
	bool isGamePaused = false;
	vector<CVEHICLE*> vehicles;
	vector<CANIMAL*> animals;
	CPEOPLE cn;
public:
	 CGAME(int n); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	 void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	 ~CGAME(); // Hủy tài nguyên đã cấp phát
	 CPEOPLE getPeople();//Lấy thông tin người
	 vector<CVEHICLE*>& getVehicle();//Lấy danh sách các xe
	 vector<CANIMAL*>& getAnimal(); //Lấy danh sách các thú
	 void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	 void exitGame(HANDLE); // Thực hiện thoát Thread
	 void startGame(); // Thực hiện bắt đầu vào trò chơi
	 void loadGame(istream); // Thực hiện tải lại trò chơi đã lưu
	 void saveGame(istream); // Thực hiện lưu lại dữ liệu trò chơi
	 void pauseGame(); // Tạm dừng Thread
	 void resumeGame(); //Quay lai Thread
	 void updatePosPeople(int); //Thực hiện điều khiển di chuyển của CPEOPLE
	 void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
	 void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	 bool getIsPaused();
	 void printPauseGameMenu();
	 void erasePasueGameMenu();
	 bool isFinish();
	 void initialForStage(int);
};

void PrintMenu();

