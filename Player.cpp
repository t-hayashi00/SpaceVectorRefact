
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
	OutputDebugString("‚¤‚Ü‚ê‚½\n");
}
Player::~Player()
{
	OutputDebugString("‚µ‚ñ‚¾\n");
}