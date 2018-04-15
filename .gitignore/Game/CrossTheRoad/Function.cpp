﻿#include "Function.h"

PointPeoplePre *headPeoplePre;

// khi người về đích hàm này sẽ được gọi để thêm vào dữ liệu
bool addPeopleFinish(int _x) {
	PointPeoplePre *p = (PointPeoplePre *)malloc(sizeof(PointPeoplePre));
	p->x = _x;
	p->next = NULL;

	if (headPeoplePre == NULL) headPeoplePre = p;
	else
	{
		p->next = headPeoplePre;
		headPeoplePre = p;
	}

	return true;
}

// xét sự va chạm khi người về đích thì hàm này được goi để xem có đụng với người đi trước hay không
bool testImpactWithPeoplePre(int _x) {
	for (PointPeoplePre *p = 0; p != NULL; p = p->next)
		if (p->x == _x) return true;

	return false;
}

// xóa hết lịch sử về đích
bool destroyHistoryPeople() {
	PointPeoplePre *p;
	while (headPeoplePre != NULL)
	{
		p = headPeoplePre;
		headPeoplePre = headPeoplePre->next;

		free(p);
	}

	return true;
}

// đếm người đã về đích
int countPeopleFinished(PointPeoplePre *p = headPeoplePre) {
	if (p == NULL) return 0;

	return countPeopleFinished(p->next) + 1;
}

bool writeHistoryToFile(FILE * f)
{
	fprintf(f, "%d ", countPeopleFinished());

	for (PointPeoplePre *p = headPeoplePre; p != NULL; p = p->next)
	{
		fprintf(f, "%d ", p->x);
	}

	return true;
}