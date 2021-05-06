DIFF_OPTIONS=-y -w --strip-trailing-cr --suppress-common-lines
build:
	@tput setaf 2
	@echo "building..."
	@tput sgr 0
	@mkdir bin -p
	g++ src/cpp/main.cpp -std=c++11 -o bin/main.exe
tests_cleanup:
	@tput setaf 2
	@echo "tests cleanup"
	@tput sgr 0
	rm -f --r out
	rm -f --r logs
00 01 02 03 04 05 06 07 08 09 10 11 12 13 14: clean build
	@tput setaf 2
	@echo "run test"
	@tput sgr 0
	@mkdir out logs -p
	bin/main.exe < in/test$@.in > out/test$@.out
	@tput setaf 2
	@echo "comparing expected with actual output..."
	@tput sgr 0
	diff expected/test$@.out out/test$@.out $(DIFF_OPTIONS) > logs/diff$@.log
tests: clean build
	@tput setaf 2
	@echo "run all tests"
	@tput sgr 0
	@mkdir out logs -p
	bin/main.exe < in/test00.in > out/test00.out
	bin/main.exe < in/test01.in > out/test01.out
	bin/main.exe < in/test02.in > out/test02.out
	bin/main.exe < in/test03.in > out/test03.out
	bin/main.exe < in/test04.in > out/test04.out
	bin/main.exe < in/test05.in > out/test05.out
	bin/main.exe < in/test06.in > out/test06.out
	bin/main.exe < in/test07.in > out/test07.out
	bin/main.exe < in/test08.in > out/test08.out
	bin/main.exe < in/test09.in > out/test09.out
	bin/main.exe < in/test10.in > out/test10.out
	bin/main.exe < in/test11.in > out/test11.out
	bin/main.exe < in/test12.in > out/test12.out
	bin/main.exe < in/test13.in > out/test13.out
	bin/main.exe < in/test14.in > out/test14.out
	bin/main.exe < in/test15.in > out/test15.out
	bin/main.exe < in/test16.in > out/test16.out
	bin/main.exe < in/test17.in > out/test17.out
	bin/main.exe < in/test18.in > out/test18.out
	bin/main.exe < in/test19.in > out/test19.out
	bin/main.exe < in/test20.in > out/test20.out
	bin/main.exe < in/test21.in > out/test21.out
	bin/main.exe < in/test22.in > out/test22.out
	bin/main.exe < in/test23.in > out/test23.out
	bin/main.exe < in/test24.in > out/test24.out
	bin/main.exe < in/test25.in > out/test25.out
	@tput setaf 2
	@echo "comparing expected with actual output..."
	@tput sgr 0
	diff -r expected out $(DIFF_OPTIONS) > logs/diff.log
	@tput setaf 7
	@tput setab 2
	@echo "all tests passed! :)"
	@tput sgr 0
clean: tests_cleanup
	@tput setaf 2
	@echo "bin cleanup"
	@tput sgr 0
	rm -f --r bin
