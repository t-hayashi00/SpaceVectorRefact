
class Player {
public:
	Player();
	~Player();
	int a ;
private:

};

Player::Player()
{
	a = 100;
	OutputDebugString("���܂ꂽ\n");
}
Player::~Player()
{
	OutputDebugString("����\n");
}