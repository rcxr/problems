DIFF_OPTIONS=-y --strip-trailing-cr -w
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
	bin/main.exe < in/input00.txt > out/output00.txt
	bin/main.exe < in/input01.txt > out/output01.txt
	bin/main.exe < in/input02.txt > out/output02.txt
	bin/main.exe < in/input03.txt > out/output03.txt
	bin/main.exe < in/input04.txt > out/output04.txt
	bin/main.exe < in/input05.txt > out/output05.txt
	bin/main.exe < in/input06.txt > out/output06.txt
	bin/main.exe < in/input07.txt > out/output07.txt
	bin/main.exe < in/input08.txt > out/output08.txt
	bin/main.exe < in/input09.txt > out/output09.txt
	bin/main.exe < in/input10.txt > out/output10.txt
	bin/main.exe < in/input11.txt > out/output11.txt
	bin/main.exe < in/input12.txt > out/output12.txt
	bin/main.exe < in/input13.txt > out/output13.txt
	bin/main.exe < in/input14.txt > out/output14.txt
	diff -r expected out $(DIFF_OPTIONS) > logs/diff.log
clean: tests_cleanup
	echo "bin cleanup"
	rm -f --r bin
