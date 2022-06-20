#include <string>

class Zombie {
public:
	void announce(void);
	void setName(std::string name);
	~Zombie();
private:
	std::string name;
};