#include "Function.h"

PointPeoplePre *headPeoplePre;

PointPeoplePre *getHeadPeoplePre() {
	return headPeoplePre;
}

// khi người về đích hàm này sẽ được gọi để thêm vào dữ liệu
bool addPeopleFinish(int _x) {
	PointPeoplePre *p = (PointPeoplePre *)malloc(sizeof(PointPeoplePre));
	p->x = _x;
	p->next = NULL;

	if (headPeoplePre != NULL)		p->next = headPeoplePre;

	headPeoplePre = p;

	return true;
}

// xét sự va chạm khi người về đích thì hàm này được goi để xem có đụng với người đi trước hay không
bool testImpactWithPeoplePre(int _x) {
	for (PointPeoplePre *p = headPeoplePre; p != NULL; p = p->next)
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


int countPeopleFinishedHide(PointPeoplePre *p = headPeoplePre) {
	if (p == NULL) return 0;

	return countPeopleFinishedHide(p->next) + 1;
}

int countPeopleFinished() {
	return countPeopleFinishedHide();
}

bool writeHistoryToFile(FILE *f)
{
	fprintf(f, "%d\n", countPeopleFinished());	// xuất số lượng người đã về đích

	for (PointPeoplePre *p = headPeoplePre; p != NULL; p = p->next)	// chạy từ người về đích cuối cùng cho tới người đầu tiên về đích
																	// 
	{
		fprintf(f, "%d ", p->x);				// xuất từng vị trí thuộc trục Ox ra file,
												// không lưu trục Oy vì khi về đích thì Oy=1
	}

	return true; 
}

bool readHistoryFromFile(FILE *f) {
	destroyHistoryPeople();

	int num_people_finished;
	fscanf(f, "%d", &num_people_finished); // nhận số lượng người đã vè đích

	int x;

	for (int i = 0; i < num_people_finished; i++)
	{
		if (feof(f)) return false;

		fscanf(f, "%d", &x); // nhận vị trí từng người đã đến đích
		addPeopleFinish(x); // 
	}
	return true;
}