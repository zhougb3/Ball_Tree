#include <iostream>

#include "BallTree.h"
#include "Utility.h"

#define FLAT

#ifdef FLAT
char dataset[L] = "Flat";
int n = 20, d = 2;
int qn = 1000;
#endif

#ifdef KINGSLEY
char dataset[L] = "Kingsley";
int n = 20, d = 4;
int qn = 1000;
#endif

#ifdef MNIST
char dataset[L] = "Mnist";
int n = 600, d = 50;
int qn = 1000;
#endif

#ifdef NETFLIX
char dataset[L] = "Netflix";
int n = 17770, d = 50;
int qn = 1000;
#endif

int main() {
	char data_path[L], query_path[L];
	char index_path[L], output_path[L];
	float** data = nullptr;
	float** query = nullptr;

	sprintf(data_path, "%s/src/dataset.txt", dataset);
	sprintf(query_path, "%s/src/query.txt", dataset);
	sprintf(index_path, "%s/index", dataset);
	sprintf(output_path, "%s/dst/answer.txt", dataset);

	if (!read_data(n, d, data, data_path)) {
		return 1;
	}

    //Kingsley added: for testing read_data function=====================================
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j <= d; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    system("pause");*/
    //for testing build tree and display result
    BallTree ball_tree1;
    ball_tree1.buildTree(n, d, data);
    ball_tree1.preorderPrint(d);
    system("pause");
    //===================================================================================

	/*BallTree ball_tree1;
	ball_tree1.buildTree(n, d, data);
	ball_tree1.storeTree(index_path);

	if (!read_data(qn, d, query, query_path));
	FILE* fout = fopen(output_path, "w");
	if (!fout) {
		printf("can't open %s!\n", output_path);
		return 1;
	}

	BallTree ball_tree2;
	ball_tree2.restoreTree(index_path);
	for (int i = 0; i < qn; i++) {
		int index = ball_tree2.mipSearch(d, query[i]);
		fprintf(fout, "%d\n", index);
	}
	fclose(fout);

	for (int i = 0; i < n; i++) {
		delete[] data[i];
	}

	for (int i = 0; i < qn; i++) {
		delete[] query[i];
	}*/

	return 0;
}