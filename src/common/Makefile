common : \
  bc_statistic.o \
  bc_algorithm.o
	ar rcs libcommon.a bc_statistic.o bc_algorithm.o

bc_statistic.o :
	gcc -c ./statistic/bc_statistic.c -o $@

bc_algorithm.o :
	gcc -c ./algorithm/bc_sort.c -o $@

test : \
  test_common.o \
  test_statistic.o \
  test_algorithm.o \
  test_utility.o
	gcc -o test_common test_common.o test_statistic.o test_algorithm.o test_utility.o -L ./ -lcommon

test_common.o :
	gcc -c ./test/test_common.c -o $@

test_statistic.o :
	gcc -c ./test/test_statistic.c -o $@

test_algorithm.o :
	gcc -c ./test/test_algorithm.c -o $@

test_utility.o :
	gcc -c ./test/test_utility.c -o $@


clean : 
	rm -f *.o *.a
	rm test_common 
