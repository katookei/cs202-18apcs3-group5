#pragma once
#include"Header.h"
#include"CCAR.h"
#include"CTRUCK.h"
#include"CBIRD.h"
#include"CDINAUSOR.h"
#include"CPEOPLE.h"

class light
{
private:
	int mX, mY;
	int color = 0;
	int object;
public:
	light();
	light(int, int, int, int);
	int lightcolor[2] = { 12,10 };
	void changecolor();
	void draw();
	int getcolor();
	int getobject();
	~light();
};

class CGAME
{
	bool isGamePaused = false;
	vector<CVEHICLE*> vehicles;
	vector<CANIMAL*> animals;
	vector<light> trafficlight;
	CPEOPLE cn;
public:
	int lvl = 1;
	 CGAME(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	 void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	 ~CGAME(); // Hủy tài nguyên đã cấp phát
	 CPEOPLE getPeople();//Lấy thông tin người
	 vector<CVEHICLE*>& getVehicle();//Lấy danh sách các xe
	 vector<CANIMAL*>& getAnimal(); //Lấy danh sách các thú
	 vector<light>& getlight();
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
	 void levelUp();
	 void initialForStage(int);
	 void level1Init();
	 void level2Init();
	 void level3Init();
	 void level4Init();
	 void win();
	 void setlight();
};

void PrintMenu();




