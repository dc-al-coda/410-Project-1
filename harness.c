#include <stdlib.h>
#include "rbtree.c"
#include "splay.c"
#include <time.h>

#define MIN_NODE 0
#define MAX_NODE 1000
#define TEST_1 10000
#define TEST_2 50000
#define TEST_REST 100000
#define TEST_END 1000000
#define TEST_INC 100000
#define NUM_RUNS 5

int main(){
	//The naming conventions of the implementations I found are confusing. The red-black tree declares a root node and the
	//splay tree declares a tree struct.`
	struct node *rb = NULL;
	struct tree *splay = TREE_EMPTY;
	clock_t start, end;
	double total_time, avg_time;
	FILE *input = fopen("./values.txt", "r");
	//FILE *ascinput = fopen("./ascvalues.txt", "r");
	//FILE *descinput = fopen("./descvalues.txt", "r");
	FILE *times = fopen("./results.txt", "w");
	int a, b, c, num;


	for(a = 0; a < NUM_RUNS; a++){
		start = clock();
		for(b = 0; b < TEST_1; b++){
			fscanf(input, "%d", &num);
			treeInsert(&splay, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Splay Random Input %d times\n", TEST_1);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = 0; a < NUM_RUNS; a++){
		treeDestroy(&splay);
		start = clock();
		for(b = 0; b < TEST_2; b++){
			fscanf(input, "%d", &num);
			treeInsert(&splay, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Splay Random Input %d times\n", TEST_2);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = TEST_REST; a <= TEST_END; a += TEST_INC){
		for(b = 0; b < NUM_RUNS; b++){
			treeDestroy(&splay);
			start = clock();
			for(c = 0; c < a; c++){
				fscanf(input, "%d", &num);
				treeInsert(&splay, num);
			}
			end = clock();
			total_time += ((double)(end-start))/CLOCKS_PER_SEC;
		}
		avg_time = total_time/NUM_RUNS;
		fprintf(times, "Splay Random Input %d times\n", a);
		fprintf(times, "%f\n\n", avg_time);
		total_time = 0;
	}

	for(a = 0; a < NUM_RUNS; a++){
		treeDestroy(&splay);
		num = -1;
		start = clock();
		for(b = 0; b < TEST_1; b++){
			if(num >= 1001){
				num =0;
			}
			else{
				num++;
			}
			treeInsert(&splay, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Splay Ascending Input %d times\n", TEST_1);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = 0; a < NUM_RUNS; a++){
		treeDestroy(&splay);
		num = -1;
		start = clock();
		for(b = 0; b < TEST_2; b++){
			if(num >= 1001){
				num =0;
			}
			else{
				num++;
			}
			treeInsert(&splay, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Splay Ascending Input %d times\n", TEST_2);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = TEST_REST; a <= TEST_END; a += TEST_INC){
		for(b = 0; b < NUM_RUNS; b++){
			treeDestroy(&splay);
			num = -1;
			start = clock();
			for(c = 0; c < a; c++){
				if(num >= 1001){
					num =0;
				}
				else{
					num++;
				}
				treeInsert(&splay, num);
			}
			end = clock();
			total_time += ((double)(end-start))/CLOCKS_PER_SEC;
		}
		avg_time = total_time/NUM_RUNS;
		fprintf(times, "Splay Ascending Input %d times\n", a);
		fprintf(times, "%f\n\n", avg_time);
		total_time = 0;
	}
	
	for(a = 0; a < NUM_RUNS; a++){
		treeDestroy(&splay);
		num = 1001;
		start = clock();
		for(b = 0; b < TEST_1; b++){
			if(num <= -1){
				num = 1000;
			}
			else{
				num--;
			}
			treeInsert(&splay, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Splay Descending Input %d times\n", TEST_1);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = 0; a < NUM_RUNS; a++){
		treeDestroy(&splay);
		num = 1001;
		start = clock();
		for(b = 0; b < TEST_2; b++){
			if(num <= -1){
				num = 1000;
			}
			else{
				num--;
			}
			treeInsert(&splay, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Splay Descending Input %d times\n", TEST_2);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;
	
	for(a = TEST_REST; a <= TEST_END; a += TEST_INC){
		for(b = 0; b < NUM_RUNS; b++){
			treeDestroy(&splay);
			num = 1001;
			start = clock();
			for(c = 0; c < a; c++){
				if(num <= -1){
					num = 1000;
				}
				else{
					num--;
				}
				treeInsert(&splay, num);
			}
			end = clock();
			total_time += ((double)(end-start))/CLOCKS_PER_SEC;
		}
		avg_time = total_time/NUM_RUNS;
		fprintf(times, "Splay Descending Input %d times\n", a);
		fprintf(times, "%f\n\n", avg_time);
		total_time = 0;
	}

	
	for(a = 0; a < NUM_RUNS; a++){
		rb = NULL;
		start = clock();
		for(b = 0; b < TEST_1; b++){
			fscanf(input, "%d", &num);
			insert(&rb, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Red Black Random Input %d times\n", TEST_1);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = 0; a < NUM_RUNS; a++){
		rb = NULL;
		start = clock();
		for(b = 0; b < TEST_2; b++){
			fscanf(input, "%d", &num);
			insert(&rb, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Red Black Random Input %d times\n", TEST_2);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = TEST_REST; a <= TEST_END; a += TEST_INC){
		for(b = 0; b < NUM_RUNS; b++){
			rb = NULL;
			start = clock();
			for(c = 0; c < a; c++){
				fscanf(input, "%d", &num);
				insert(&rb, num);
			}
			end = clock();
			total_time += ((double)(end-start))/CLOCKS_PER_SEC;
		}
		avg_time = total_time/NUM_RUNS;
		fprintf(times, "Red Black Random Input %d times\n", a);
		fprintf(times, "%f\n\n", avg_time);
		total_time = 0;
	}

	for(a = 0; a < NUM_RUNS; a++){
		rb = NULL;
		num = -1;
		start = clock();
		for(b = 0; b < TEST_1; b++){
			if(num >= 1001){
				num =0;
			}
			else{
				num++;
			}
			insert(&rb, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Red Black Ascending Input %d times\n", TEST_1);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = 0; a < NUM_RUNS; a++){
		rb = NULL;
		num = -1;
		start = clock();
		for(b = 0; b < TEST_2; b++){
			if(num >= 1001){
				num =0;
			}
			else{
				num++;
			}
			insert(&rb, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Red Black Ascending Input %d times\n", TEST_2);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = TEST_REST; a <= TEST_END; a += TEST_INC){
		for(b = 0; b < NUM_RUNS; b++){
			rb = NULL;
			num = -1;
			start = clock();
			for(c = 0; c < a; c++){
				if(num >= 1001){
					num =0;
				}
				else{
					num++;
				}
				insert(&rb, num);
			}
			end = clock();
			total_time += ((double)(end-start))/CLOCKS_PER_SEC;
		}
		avg_time = total_time/NUM_RUNS;
		fprintf(times, "Red Black Ascending Input %d times\n", a);
		fprintf(times, "%f\n\n", avg_time);
		total_time = 0;
	}
	
	for(a = 0; a < NUM_RUNS; a++){
		rb = NULL;
		num = 1001;
		start = clock();
		for(b = 0; b < TEST_1; b++){
			if(num <= -1){
				num = 1000;
			}
			else{
				num--;
			}
			insert(&rb, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Red Black Descending Input %d times\n", TEST_1);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = 0; a < NUM_RUNS; a++){
		rb = NULL;
		num = 1001;
		start = clock();
		for(b = 0; b < TEST_2; b++){
			if(num <= -1){
				num = 1000;
			}
			else{
				num--;
			}
			insert(&rb, num);
		}
		end = clock();
		total_time += ((double)(end-start))/CLOCKS_PER_SEC;
	}
	avg_time = total_time/NUM_RUNS;
	fprintf(times, "Red Black Descending Input %d times\n", TEST_2);
	fprintf(times, "%f\n\n", avg_time);
	total_time = 0;

	for(a = TEST_REST; a <= TEST_END; a += TEST_INC){
		for(b = 0; b < NUM_RUNS; b++){
			rb = NULL;
			num = 1001;
			start = clock();
			for(c = 0; c < a; c++){
				if(num <= -1){
					num = 1000;
				}
				else{
					num--;
				}
				insert(&rb, num);
			}
			end = clock();
			total_time += ((double)(end-start))/CLOCKS_PER_SEC;
		}
		avg_time = total_time/NUM_RUNS;
		fprintf(times, "Red Black Descending Input %d times\n", a);
		fprintf(times, "%f\n\n", avg_time);
		total_time = 0;
	}
	
	
	fclose(input);
	//fclose(ascinput);
	//fclose(descinput);
	fclose(times);

	free(rb);
        free(splay);	
	return 0;
}
