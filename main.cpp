#include <bangtal>
#include <string>
using namespace std;
using namespace bangtal;

class Door : public Object {
public:
	static ObjectPtr create(const string& image, ScenePtr scene = nullptr, int x = 0, int y = 0, bool shown = true) {
		auto object = ObjectPtr(new Door(image, scene, x, y, shown));
		Object::add(object);
		return object;
	}

protected:
	Door(const string& image, ScenePtr scene, int x, int y, bool shown) : Object(image, scene, x, y, shown) {}

public:
	virtual bool onMouse(int x, int y, MouseAction action) {
		if (!Object::onMouse(x, y, action)) {
			showMessage("´ÝÇû½À´Ï´Ù.");
		}
		return true;
	}
};

class LockedDoor : public Door {
public:
	static ObjectPtr create(const string& image, ScenePtr scene = nullptr, int x = 0, int y = 0, bool shown = true) {
		auto object = ObjectPtr(new LockedDoor(image, scene, x, y, shown));
		Object::add(object);
		return object;
	}

protected:
	LockedDoor(const string& image, ScenePtr scene, int x, int y, bool shown) : Door(image, scene, x, y, shown) {}

public:
	virtual bool onMouse(int x, int y, MouseAction action) {
		if (!Object::onMouse(x, y, action)) {
			showMessage("Àá°å½À´Ï´Ù.");
		}
		return true;
	}
};

int main(void)
{
	auto scene = Scene::create("¹® »ó¼Ó", "images/¹è°æ-1.png");
	auto closed_door = Door::create("images/¹®-¿À¸¥ÂÊ-´ÝÈû.png", scene, 800, 270);
	auto locked_door = LockedDoor::create("images/¹®-¿ÞÂÊ-´ÝÈû.png", scene, 200, 280);

	startGame(scene);
	return 0;
}