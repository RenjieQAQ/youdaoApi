## 测试有道翻译接口
### md5的使用示例
	void PrintMD5(const string &str, MD5 &md5) {  
		cout << "MD5(\"" << str << "\") = " << md5.toString() << endl;  
	}  
	int main() {  
		cout << MD5("abc").toString() << endl;  //初始化
		MD5 md5;  
		md5.update("");  
		PrintMD5("", md5);  
		md5.update("a");   //增添字符串
		PrintMD5("a", md5);  
		md5.update("bc");  
		PrintMD5("abc", md5);  
		md5.update("defghijklmnopqrstuvwxyz");  
		PrintMD5("abcdefghijklmnopqrstuvwxyz", md5);  
		md5.reset();  
		md5.update("message digest");  
		PrintMD5("message digest", md5);  
		return 0;  
	}  