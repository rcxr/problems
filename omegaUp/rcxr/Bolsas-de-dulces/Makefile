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
	bin/main.exe < in/input$@.txt > out/output$@.txt
	@tput setaf 2
	@echo "comparing expected with actual output..."
	@tput sgr 0
	diff expected/output$@.txt out/output$@.txt $(DIFF_OPTIONS) > logs/diff$@.log
tests: clean build
	@tput setaf 2
	@echo "run all tests"
	@tput sgr 0
	@mkdir out logs -p
	bin/main.exe < in/input00.txt > out/output00.txt
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
