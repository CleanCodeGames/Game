#pragma once
#include "Button.h"
class MenuSelectMap : public B
{
private:

	vector<string> vec_map_list;

public:

	void CheckMaps() {
		const string path = "maps\\";
		const string extension = ".wemap";
		for (auto& p : fs::directory_iterator(path)) {
			if (p.path().extension().string() == extension) {
				string fNime = p.path().filename().string();
				fNime.erase(fNime.length() - 6);
				vec_map_list.push_back(fNime);
			}
		}
		for (auto& map_name : vec_map_list) {
			cout << map_name << endl;
		}
	}

	MenuSelectMap() {

	}

	void Update() {

	}

	void Action() {

	}

	void Draw() {

	}

	~MenuSelectMap() {

	}
};