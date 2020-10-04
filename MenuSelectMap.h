#pragma once
#include "Button.h"
class MenuSelectMap : public B
{
private:

	vector<string> vec_map_list;
	vector<unique_ptr<AbstractButton>> vec_button_maps;

public:

	void CheckMaps() {
		vec_button_maps.clear();
		vec_map_list.clear();
		const string path = "maps\\";
		const string extension = ".wemap";
		for (auto& p : fs::directory_iterator(path)) {
			if (p.path().extension().string() == extension) {
				string fNime = p.path().filename().string();
				fNime.erase(fNime.length() - 6);
				vec_map_list.push_back(fNime);
			}
		}
		int counter = 0;
		for (auto& map_name : vec_map_list) {
			cout << map_name << endl;
			vec_button_maps.push_back(make_unique<ButtonClickActiveWithText>(CreateShape(v2f(300, 25 * counter), v2f(120, 24), -1, color_panel_in, color_panel_out), map_name));
			counter++;
		}
	}

	MenuSelectMap() {
	}

	void Update() {
		for (auto& button_map : vec_button_maps) {
			button_map->Update();
		}
	}

	void Action() {
		for (auto& button_map : vec_button_maps) {
			if (button_map->Action()) {
				cout << button_map->GetActionId() << endl;
			}
		}
	}

	void Draw() {
		for (auto& button_map : vec_button_maps) {
			button_map->Draw();
		}
	}

	~MenuSelectMap() {

	}
};