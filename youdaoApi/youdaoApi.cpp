#include "youdaoApi.h"


#include<cstdlib>
#include<ctime>


youdaoApi::youdaoApi() :
	md5("")
{
	cout << "youdaoApi" << endl;
	srand((unsigned)time(NULL));
	word = "good";
	appkey = "53b6a2f0256f706f";
	from = "EN";
	to = "zh-CHS";
	salt = to_string(rand() % 10);
	appSecret = "QBf5lkcw1OHulQ2LgLCgT4DeuWLx3Xvc";
	md5Str = appkey + word + salt + appSecret;
	md5.update(md5Str);
	sign = md5.toString();
	ostringstream os;
	os << "http://openapi.youdao.com/api?appKey=" << appkey << "&q=" << word << "&from=" << from << "&to=" << to << "&sign=" << sign << "&salt=" << salt;
	url = os.str();
	cout << "url:" << url << endl;
}


youdaoApi::~youdaoApi()
{
}
