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
	bin/main.exe < in/input15.txt > out/output15.txt
	bin/main.exe < in/input16.txt > out/output16.txt
	bin/main.exe < in/input17.txt > out/output17.txt
	bin/main.exe < in/input18.txt > out/output18.txt
	bin/main.exe < in/input19.txt > out/output19.txt
	bin/main.exe < in/input20.txt > out/output20.txt
	bin/main.exe < in/input21.txt > out/output21.txt
	bin/main.exe < in/input22.txt > out/output22.txt
	bin/main.exe < in/input23.txt > out/output23.txt
	bin/main.exe < in/input24.txt > out/output24.txt
	bin/main.exe < in/input25.txt > out/output25.txt
	bin/main.exe < in/input26.txt > out/output26.txt
	bin/main.exe < in/input27.txt > out/output27.txt
	diff -r expected out $(DIFF_OPTIONS) > logs/diff.log
clean: tests_cleanup
	echo "bin cleanup"
	rm -f --r bin
