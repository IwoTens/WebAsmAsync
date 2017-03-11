# WebAsmAsync
1. Compile as:

emcc main.cpp -o main.js -s EXPORTED_FUNCTIONS="['_async']" -s RESERVED_FUNCTION_POINTERS=2 -s ASYNCIFY=1 -s ASYNCIFY_FUNCTIONS="['_async']" -std=c++11


emcc -std=c++11 worker.cpp -s EXPORTED_FUNCTIONS="['_one']" -o worker.js  -s BUILD_AS_WORKER=1


2. Test - open index.html, push the button (you will see messge box before and after call async) and wait 20 sec. While waiting, the page is not blocked. After 20 sec. thread will call main thread.

3. Web browsers - IE (11.0.9600.18499), FireFox Nightly 55.0.a1, FireFox 52.0. On Chrome doesn't work for now.
