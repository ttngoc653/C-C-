#include<stdlib.h>

#include<stdio.h>

struct PointPeoplePre
{
	int x;
	PointPeoplePre *next;
};

// khi người về đích hàm này sẽ được gọi để thêm vào dữ liệu
bool addPeopleFinish(int _x);

// xét sự va chạm khi người về đích thì hàm này được goi để xem có đụng với người đi trước hay không
bool testImpactWithPeoplePre(int _x);

bool destroyHistoryPeople();

bool writeHistoryToFile(FILE *f);