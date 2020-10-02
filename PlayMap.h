#pragma once
#include "System.h"

/*—юда помещаем все игровые объекты и обрабатываем их*/

class PlayMap : public B
{
private:

protected:

public:

	virtual bool LoadFromFile(string fNime) {
		ifstream file;
		const string path = "maps\\";
		const string extension = ".wemap";
		file.open(path + fNime + extension);

		if (file.is_open()) {
			return true;
		}
		return false;
	}

	PlayMap() {

	}

	virtual void Update() {

	}

	virtual void Action() {

	}

	virtual void Draw() {

	}

	virtual ~PlayMap() {

	}
};