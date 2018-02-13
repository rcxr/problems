DIFF_OPTIONS=-y -w --strip-trailing-cr --suppress-common-lines
build:
	echo "g++"
	mkdir bin -p
	g++ src/main.cpp -std=c++11 -o bin/main.exe
tests_cleanup:
	echo "tests cleanup"
	rm -f --r out
	rm -f --r logs
00 01 02 03 04 05 06 07 08 09 10 11 12 13 14: clean build
	echo "run test"
	mkdir out logs -p
	bin/main.exe < in/input$@.txt > out/output$@.txt
	diff expected/output$@.txt out/output$@.txt $(DIFF_OPTIONS) > logs/diff$@.log
tests: clean build
	echo "run all tests"
	mkdir out logs -p
	bin/main.exe < in/input18.txt > out/output18.txt
	bin/main.exe < in/input19.txt > out/output19.txt
	diff -r expected out $(DIFF_OPTIONS) > logs/diff.log
clean: tests_cleanup
	echo "bin cleanup"
	rm -f --r bin
