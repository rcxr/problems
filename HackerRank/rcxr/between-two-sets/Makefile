DIFF_OPTIONS=-y --strip-trailing-cr -w
build:
	echo "g++"
	g++ main.cpp -std=c++11 -o main.exe
tests_cleanup:
	echo "tests cleanup"
	rm -f --r out/*
	rm -f --r logs/*
00 01 02 03 04 05 06 07 08 09 10 11 12 13 14: clean build
	echo "run test"
	mkdir out logs -p
	./main.exe < in/input$@.txt > out/output$@.txt
	diff expected/output$@.txt out/output$@.txt $(DIFF_OPTIONS) > logs/diff$@.log
tests: clean build
	echo "run all tests"
	mkdir out logs -p
	./main.exe < in/input00.txt > out/output00.txt
	./main.exe < in/input01.txt > out/output01.txt
	diff -r expected out $(DIFF_OPTIONS) > logs/diff.log
clean: tests_cleanup
	rm -f main.exe
