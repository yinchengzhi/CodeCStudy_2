
#include<Windows.h>

//������������ģ���ʱ�����ֱ�ӵ���

_declspec(dllexport) void go() {

	//double db[1234567];			//����ջ�Ĵ�С
	wihle(-1){
		double db[1024 * 100];			//8*100*1024 ������ 1M
	}

	//ջ���Զ����䣬�Զ��ͷţ���������cpu��Դ

	//dll�����ƻ���ľ
}

//������������ģ���ʱ�����ֱ�ӵ���

_declspec(dllexport) void goA() {

	//double db[1234567];			//����ջ�Ĵ�С

	MessageBox(0, "test", "test1", 0);
	//dll �ƻ���ľ


}