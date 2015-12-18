common : \
  bc_statistic.o \
  bc_algorithm.o \
  bc_logging.o \
  log4c.o
	ar rcs libbccommon.a bc_statistic.o bc_algorithm.o bc_logging.o log4c.o

bc_statistic.o :
	gcc -c ./statistic/bc_statistic.c -o $@

bc_algorithm.o :
	gcc -c ./algorithm/bc_sort.c -o $@

bc_logging.o :
	gcc -c ./logging/bc_logging.c -o $@

log4c.o :
	gcc -c ./logging/log4c.c -o $@
 
test : \
  test_common.o \
  test_statistic.o \
  test_algorithm.o \
  test_utility.o \
  test_logging.o 
	gcc -o test_common test_common.o test_statistic.o test_algorithm.o test_utility.o test_logging.o  -L ./ -lbccommon -lm

test_common.o :
	gcc -c ./test/test_common.c -o $@

test_statistic.o :
	gcc -c ./test/test_statistic.c -o $@

test_algorithm.o :
	gcc -c ./test/test_algorithm.c -o $@

test_utility.o :
	gcc -c ./test/test_utility.c -o $@

test_logging.o :
	gcc -c ./test/test_logging.c -o $@

clean : 
	rm -f *.o *.a
	rm test_common 
