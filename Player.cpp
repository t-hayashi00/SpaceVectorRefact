
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
	OutputDebugString("うまれた\n");
}
Player::~Player()
{
	OutputDebugString("しんだ\n");
}