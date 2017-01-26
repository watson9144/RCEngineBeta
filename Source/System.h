//系统基类
class CSystemBase
{
public:
	//释放
	virtual ~CSystemBase() = 0;

	//更新
	virtual int Update() = 0;

	//初始化
	virtual int Initialize() = 0;
};